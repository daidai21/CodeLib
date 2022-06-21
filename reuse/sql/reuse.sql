
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
    `id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'id',
    `create_time` datetime DEFAULT CURRENT_TIMESTAMP COMMENT '创建时间',
    `update_time` datetime DEFAULT CURRENT_TIMESTAMP ON CURRENT_TIMESTAMP COMMENT '更新时间',
    `deleted_time` datetime DEFAULT NULL COMMENT '删除时间',
    `note` varchar(500) DEFAULT NULL COMMENT '备注',

    PRIMARY KEY ( `id` )
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8 COMMENT='测试表';


-- 表加一列,在id列之后
ALTER TABLE t_person
ADD COLUMN cnt BIGINT NOT NULL DEFAULT '0' COMMENT '数量' AFTER id
;



SHOW status LIKE 'Com_select%';
SHOW status LIKE 'Com_insert%';
SHOW status LIKE 'Com_update%';
SHOW status LIKE 'Com_delete%';
SHOW status LIKE 'Com_commit%';


SHOW status LIKE "Slow_queries";

status;
