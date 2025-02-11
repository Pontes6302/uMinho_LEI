{-|
Module      : Ficha4
Description : Módulo Haskell contendo ficha 4 de PF.
Copyright   : (c) Sívio <a100762@uminho.pt>, 2024
Stability   : experimental
Portability : POSIX

Gestão de informação em listas.
-}

module Ficha4 where

import Data.Char
import Data.List (inits)
import Text.Read (Lexeme(String))

digitAlpha :: String -> (String,String)
digitAlpha str = (letras, digitos)
    where
        letras = [x | x <- str, isAlpha x]
        digitos = [x | x <- str, isDigit x]

nzp :: [Int] -> (Int,Int,Int)
nzp (x:xs)
    | x > 0 = (n, z, p+1)
    | x < 0 = (n+1, z, p)
    | otherwise = (n, z+1, p)
    where
        (n,z,p) = nzp xs

divMod2 :: Integral a => a -> a -> (a, a)
divMod2 x 0 = error "Divisão por zero"
divMod2 x y
    | x < y = (0, x)
    | otherwise = (int + 1, resto)
    where
        (int, resto) = divMod2 (x-y) y

fromDigits :: [Int] -> Int
fromDigits [] = 0
fromDigits (h:t) = h*10^length t + fromDigits t

fromDigitsEx :: [Int] -> Int
fromDigitsEx [] = 0
fromDigitsEx x = fromDigitsExAux x 0
    where
        fromDigitsExAux [] ac = ac
        fromDigitsExAux (x:xs) ac = fromDigitsExAux xs (x*10^length xs + ac)

fromDigitsEx2 :: [Int] -> Int
fromDigitsEx2 [] = 0
fromDigitsEx2 x = fromDigitsExAux x (length x - 1)
    where
        fromDigitsExAux [] _ = 0
        fromDigitsExAux (x:xs) l = x*10^l + fromDigitsExAux xs (l - 1)

maxSumInit :: (Num a, Ord a) => [a] -> a
maxSumInit l = maximum [sum m | m <- inits l]

maxSumInitmeuAux :: (Num a, Ord a) => [[a]] -> a -> a
maxSumInitmeuAux [] ac = ac
maxSumInitmeuAux (x:xs) ac
    | sum x > ac = maxSumInitmeuAux xs (sum x)
    | otherwise = maxSumInitmeuAux xs ac

maxSumInitmeu :: (Num a, Ord a) => [a] -> a
maxSumInitmeu l = maxSumInitmeuAux (inits l) 0

fib :: Int -> Int
fib x = fibAux x 0 1
    where
        fibAux :: Int -> Int -> Int -> Int
        fibAux 0 a _ = a
        fibAux n a b = fibAux (n-1) b (b+a)

intToStr :: Int -> String
intToStr n = intToStrAux n []

intToStrAux :: Int -> String -> String
intToStrAux 0 s = s
intToStrAux n s = intToStrAux (n `div` 10) (chr (n `mod` 10 + 48) : s)

a8 = [x | x<- [1..20], x `mod` 6 == 0] --[6, 12, 18]
b8 = [x | x<- [1..20], x `mod` 6 == 0] --[6, 12, 18]
c8 = [(x,30-x) | x <- [10..20]]
--d8 = []

a9 = [2^x | x <- [0..10]]
b9 = [(n,6 - n) | n <- [1..5]]
c9 = [[1..x] | x <- [1..5]]
d9 = [replicate x 1 | x <- [1..5]]
e9 = [product [1..x] | x <- [1..6]]