--
-- Unidade Curricular de Bases de Dados.
-- Sistemas de Dados Relacionais.
--
-- Instruções Pré Compiladas
-- (Pré Preparadas)
-- Criação, alteração e remoção de instruções pré preparadas.
--
-- Exemplos de Aplicação.
-- Belo, O., 2024
--

-- MySQL Prepared Statement
-- Instruções pré preparadas ou pré compiladas
-- PREPARE FROM
-- EXECUTE
-- DEALLOCATE PREPARE

-- Indicação da Base de Dados de Trabalho.
USE Sakila;

-- Exemplo 01
-- Consulta de todos os registos da tabela "Customer"
PREPARE selCustomer FROM 
	'SELECT * FROM Customer';
EXECUTE selCustomer;
DEALLOCATE PREPARE selCustomer;



-- Exemplo 02
-- Consulta do registo de um cliente da tabela "Customer"
PREPARE selCustomerI FROM 
	'SELECT * FROM Customer WHERE Customer_Id = ? ';
--
SET @Id = '1';
EXECUTE selCustomerI USING @Id;
--
DEALLOCATE PREPARE selCustomerI;

-- Exemplo 03
-- Inserção de um registo na tabela "Customer"
-- (1) Definição da instrução pré compilada
PREPARE insCustomer FROM 
	'INSERT INTO Customer 
		(Store_Id, First_Name, Last_Name, eMail, Address_Id, Active) 
		VALUES (?, ?, ?, ?, ?, ?)';
-- (2) Execução da instrução pré compilada
SET @Store_Id = '1';
SET @First_Name = 'Bernardino';
SET @Last_Name = 'Ruas', @eMail = 'bern@email.com';
SET @Address_Id = '5';
SET @Active = '1';
EXECUTE insCustomer 
	USING @Store_Id, @First_Name, @Last_Name, @eMail, @Address_Id, @Active;

SELECT * FROM Customer
	WHERE First_Name = 'Bernardino';

-- (3) Remoção da definição da instrução pré compilada
-- Libertação dos recursos reservados.
DEALLOCATE PREPARE insCustomer;

-- Exemplo 04
-- Remoção de um registo na tabela "Customer"
--
PREPARE remCustomer FROM 
	'DELETE FROM Customer WHERE Id = ?';
--
SET @Id = '610';
EXECUTE remCustomer USING @Id;
--
SELECT * FROM Customer
	WHERE Customer_Id = '610';
--
DEALLOCATE PREPARE remCustomer;

--
-- <fim>
