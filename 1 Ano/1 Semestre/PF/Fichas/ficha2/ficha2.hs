{-|
Module      : Ficha2
Description : Módulo Haskell contendo ficha 2 de PF.
Copyright   : (c) Sívio <a100762@uminho.pt>, 2024
Stability   : experimental
Portability : POSIX

Este módulo contém definições Haskell para o cálculo de funções recursivas sobre listas.
-}

{-|
Exercício 1
a: 39
b: [8, 12]
c: [3, 4, 5]
d: "certo"
-}

type Polinomio = [Monomio]
type Monomio = (Float,Int)

conta :: Int -> Polinomio -> Int
conta _ [] = 0
conta n ((x,p):xs)
    | p == n = 1 + conta n xs
    |otherwise = conta n xs

grau :: Polinomio -> Int
grau [] = 0
grau ((x,y):xs) = max y (grau xs)

selgrau :: Int -> Polinomio -> Polinomio
selgrau _ [] = []
selgrau n ((x,y):xs)
    | y == n = (x,y):selgrau n xs
    | otherwise = selgrau n xs

remgrau :: Int -> Polinomio -> Polinomio
remgrau _ [] = []
remgrau n ((x,y):xs)
    | n /= y = (x,y):remgrau n xs
    | otherwise = remgrau n xs

somacoef :: Polinomio -> Float
somacoef [] = 0
somacoef ((x,y):xs) = x+somacoef xs

normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza ((x,y):xs) = (somacoef msmGrau, y):normaliza menosGrau
    where
        msmGrau = selgrau y ((x,y):xs)
        menosGrau = remgrau y xs

ordena :: Polinomio -> Polinomio
ordena [] = []
ordena l = selgrau maxGrau l ++ ordena (remgrau maxGrau l)
    where
        maxGrau = grau l