module Ficha9 where

import System.Random

bingo :: IO ()
bingo = bingoaux [] 10

bingoaux :: [Int] -> Int -> IO ()
bingoaux l n = do
    x <- randomRIO (1,10::Int)
    if x `elem` l then bingoaux l n
    else do
        putStrLn $ "Número: " ++ show x
        k <- getLine
        if n == 1 then return ()
        else bingoaux (x:l) (n-1)

mastermind :: IO ()
mastermind = do
    x <- randomRIO (1000,9999::Int)
    mastermindaux x

mastermindaux :: Int -> IO ()
mastermindaux x = do
    putStrLn "Introduza um número de 4 dígitos:"
    y <- getLine
    if x == read y then putStrLn "Parabéns!"
    else do
        let z = mastermindcheck x (read y)
        putStrLn $ "Número de dígitos corretos: " ++ show (fst z)
        putStrLn $ "Número de dígitos errados: " ++ show (snd z)
        mastermindaux x

mastermindcheck :: Int -> Int -> (Int,Int)
mastermindcheck x y = mastermindcheckaux (show x) (show y) (0,0)
    where
        mastermindcheckaux :: String -> String -> (Int,Int) -> (Int,Int)
        mastermindcheckaux [] [] (a,b) = (a,b)
        mastermindcheckaux (x:xs) (y:ys) (a,b)
            | x == y    = mastermindcheckaux xs ys (a+1, b)
            | otherwise = mastermindcheckaux xs ys (a, b+1)
        mastermindcheckaux _ _ (a,b) = (a,b)

data Aposta = Ap [Int] (Int,Int)

valida :: Aposta -> Bool
valida (Ap l (x,y)) = length l == 5 && x >= 1 && x <= 9 && y >= 1 && y <= 9 && validaAux l
    where
        validaAux :: [Int] -> Bool
        validaAux [] = True
        validaAux (x:xs) = x >= 1 && x <= 50 && validaAux xs

comuns :: Aposta -> Aposta -> (Int,Int)
comuns (Ap l1 e1) (Ap l2 e2) = (auxNums l1 l2, auxEst e1 e2)
    where
        auxEst (x,y) (a,b)
            | x == a && y == b = 2
            | x == a || y == b = 1
            | otherwise = 0
        auxNums :: [Int] -> [Int] -> Int
        auxNums [] _ = 0
        auxNums (x:xs) l
            | x `elem` l = 1 + auxNums xs l
            | otherwise = auxNums xs l

instance Eq Aposta where
    (==) (Ap l1 e1) (Ap l2 e2) = l1 == l2 && e1 == e2

premio :: Aposta -> Aposta -> Maybe Int
premio a1 a2 = case comuns a1 a2 of
    (5,2) -> Just 1
    (5,1) -> Just 2
    (5,0) -> Just 3
    (4,2) -> Just 4
    (4,1) -> Just 5
    (4,0) -> Just 6
    (3,2) -> Just 7
    (2,2) -> Just 8
    (3,1) -> Just 9
    (3,0) -> Just 10
    (1,2) -> Just 11
    (2,1) -> Just 12
    (2,0) -> Just 13
    (0,2) -> Just 14
    _ -> Nothing

leAposta :: IO Aposta
leAposta = do
    putStrLn "Introduza os números da aposta:"
    n <- leApostaAux 5 []
    putStrLn "Introduza os números das estrelas:"
    e <- leApostaAux 2 []
    if valida (Ap n (head e, last e)) then
        return (Ap n (head e, last e)) 
        else do
            putStrLn "Aposta inválida!"
            leAposta
    where
        leApostaAux :: Int -> [Int] -> IO [Int]
        leApostaAux 0 l = return l
        leApostaAux n l = do
            x <- getLine
            leApostaAux (n-1) (read x:l)

joga :: Aposta -> IO ()
joga a = do
    b <- leAposta
    let s = case premio a b of
            Just x -> "Parabéns! Ganhou o prémio "
            Nothing -> "Não foi desta vez!"
    putStrLn s