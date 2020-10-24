
-- create db
CREATE DATABASE IF NOT EXISTS test;

SHOW databases;
-- select db
use test;
-- show used db
SELECT database();

SHOW tables;

-- create tb
CREATE TABLE IF NOT EXISTS `test` (
   `id` BIGINT AUTO_INCREMENT,
   `name` VARCHAR(100) NOT NULL,
   PRIMARY KEY ( `id` )
);




SHOW status LIKE 'Com_select%';
SHOW status LIKE 'Com_insert%';
SHOW status LIKE 'Com_update%';
SHOW status LIKE 'Com_delete%';
SHOW status LIKE 'Com_commit%';


SHOW status LIKE "Slow_queries";

status;
