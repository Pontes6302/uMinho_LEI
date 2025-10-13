--
-- Unidade Curricular de Bases de Dados.
-- Sistemas de Dados Relacionais.
--
-- Importação e exportação de dados de e para ficheiros externos.
--
-- Exemplos de Aplicação.
-- Belo, O., 2024.
--

-- Obs.: As instruções apresentadas apenas podem ser executadas com o utilitário mysqldump
-- através da consola do sistema operativo.
--
 
-- B A C K U P 
--
-- Realização de um backup simples de uma base de dados
> mysqldump  -u root –p sakila > E:\BackupsMySQL\sakila.sql

-- Realização de um backup de uma base de dados para um ficheiro com  etiqueta temporal integrando a data e hora da sua realização
> mysqldump -u root -p sakila > E:\BackupsMySQL\Sakila-Backup-%date:/=%-%time:~0,2%%time:~3,2%.sql

-- Backup simultâneo de todas as bases de dados do servidor MySQL
> mysqldump -u root -p --all-databases > E:\ BackupsMySQL\BasesMySQL-Backup-%date:/=%-%time:~0,2%%time:~3,2%.sql

-- Backup simultâneo de duas bases de dados
> mysqldump -u root -p --databases mercearia sakila > E:\BackupsMySQL\Mercearia-Sakila-Backup-%date:/=%-%time:~0,2%%time:~3,2%.sql

-- Backup de uma tabela de uma base de dados
> mysqldump -u root -p mercearia cliente > E:\BackupsMySQL\Mercearia-Cliente-Backup-%date:/=%-%time:~0,2%%time:~3,2%.sql 

-- Backup de uma base de dados com registo do resultado da execução do mysqldump num ficheiro adicional
> mysqldump  -u root –p --result-file=Results.sql mercearia > E:\BackupsMySQL\Mercearia-Backup.sql


-- R E C U P E R A Ç Ã O 
--
-- Recuperação de uma base de dados a partir de um ficheiro externo.
> mysql -u root -p sakila < E:\BackupsMySQL\Sakila-Backup-20200512-18:23.sql

-- Recuperação de uma base de dados a partir de um ficheiro compactado:
> gunzip < E:\BackupsMySQL\Sakila-Backup-20200512-18:23.sql.zip | mysql -u root –p Sakila

--
-- <fim>
