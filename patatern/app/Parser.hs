{-# LANGUAGE OverloadedStrings #-}
module Parser where

import Data.Text (Text)
import Data.Char
import qualified Data.Text as T
import Data.Void
import Text.Megaparsec
import Text.Megaparsec.Char
import qualified Text.Megaparsec.Char.Lexer as L
import SyntaxTree

type Parser = Parsec Void Text

sc :: Parser ()
sc = L.space
  space1
  (L.skipLineComment ";")
  (L.skipBlockComment "{-" "-}")

lexeme :: Parser a -> Parser a
lexeme = L.lexeme sc

keyword :: Text -> Parser Text
keyword = L.symbol sc

isOperator :: Char -> Bool
isOperator c = c `elem` ['+', '-', '*', '/', '?', '=', '<', '>']

symbol :: Parser Text
symbol = T.pack <$> lexeme chars
  where
    chars = (:) <$> symbolStart <*> symbolCont
    symbolStart = satisfy (\c -> isLower c || isOperator c)
    symbolCont = many $ satisfy (\c -> isOperator c || isAlphaNum c)

variable :: Parser Text
variable = T.pack <$> lexeme chars
  where
    chars = (:) <$> symbolStart <*> symbolCont
    symbolStart = upperChar
    symbolCont = many $ satisfy (\c -> isAlphaNum c || isOperator c)

int :: Parser Integer
int = lexeme (L.signed (return ()) L.decimal <* notFollowedBy nonDigit)
  where nonDigit = satisfy (\c -> isOperator c || isAlpha c)

list :: Parser (Term Text)
list = do
    ts <- many atom
    return $ foldr (:>) (Symbol "fin") ts

atom :: Parser (Term Text)
atom = choice
  [ between (keyword "(") (keyword ")") term
  , between (keyword "[") (keyword "]") list
  -- We parse plus or minus symbols on their own
  -- to avoid ambiguity with signs of numbers
  , Int <$> try int
  , Symbol <$> symbol
  , Var <$> variable
  ]

term :: Parser (Term Text)
term = do
    ts <- some atom
    return $ foldl1 (:>) ts

rule :: Parser (Rule Text)
rule = do
    lhs <- term
    rhs <- option [] $ do
      keyword ":"
      sepBy term (keyword ",")
    keyword "."
    return $ Rule lhs rhs

queryTerms :: Parser [Term Text]
queryTerms = do
    terms <- sepBy term (keyword ",")
    keyword "."   
    pure terms

program :: Parser [Rule Text]
program = many rule <* eof

parseQueryTerms :: Text -> Either String [Term Text]
parseQueryTerms input =
  case parse (sc *> queryTerms) "#REPL#" input of
    Left err -> Left $ errorBundlePretty err
    Right res -> Right res

parseProgram :: String -> Text -> Either String [Rule Text]
parseProgram filename input =
  case parse (sc *> program) filename input of
    Left err -> Left $ errorBundlePretty err
    Right res -> Right res
