--
-- Unidade Curricular de Bases de Dados.
-- Sistemas de Dados Relacionais.
--
-- Importação e exportação de dados de e para ficheiros externos.
--
-- Exemplos de Aplicação.
-- Belo, O., 2024.
--

-- Base de Dados de Trabalho.
USE Sakila;

-- Importação de Dados a partir de Ficheiros Externos
-- Exemplo 01
LOAD DATA INFILE 'C:/Data/FilmPromotions.csv' 
		INTO TABLE FilmPromotions -- É necessário criar a tabela. 
		FIELDS TERMINATED BY ',' 
		ENCLOSED BY '"'
		LINES TERMINATED BY '\n'
		IGNORE 1 ROWS;
        
-- Exportação de Dados para Ficheiros Externos
-- Exemplo 01
SELECT *
	FROM Customer
	INTO OUTFILE 'C:/Data/SakilaCustomer.txt';

-- Exemplo 02
SELECT Id, CONCAT(First_Name,' ',Last_Name), eMail
	FROM cCustomer
	INTO OUTFILE 'C:/Data/SakilaCustomer.csv'
	FIELDS TERMINATED BY ','
	ENCLOSED BY '"'
	LINES TERMINATED BY '\n';

-- Exemplo 03
-- Inclusão de um cabeçalho
SELECT 'Id', 'Nome Próprio', 'Apelido'
	UNION ALL
SELECT Id, First_Name, Last_Name
	FROM customer
	INTO OUTFILE 'C:/Data/SakilaCustomer.csv'
	FIELDS TERMINATED BY ','
	ENCLOSED BY '"'
	LINES TERMINATED BY '\n';
    
-- Exemplo 04
-- Para um ficheiro JSON
SELECT 
    CONCAT("[",
         GROUP_CONCAT(
              CONCAT("{Customer_Id:'",Customer_Id,"',"),
              CONCAT("First_Name:'",First_Name,"',"),
              CONCAT("Last_Name:'",Last_Name,"',"),
              CONCAT("eMail:'",eMail,"'}")
         )
    ,"]") 
AS json FROM Customer
INTO OUTFILE 'C:/Data/SakilaCustomer.json'    

--
SELECT @@GLOBAL.secure_file_priv;

--
-- <fim>