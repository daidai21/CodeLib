
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


-- 删除数据
UPDATE t_test
SET column1=value1,
    column2=value2,...
    deleted_time = CURRENT_TIMESTAMP()
WHERE some_column=some_value;


-- 查询
SELECT col1,
        col2,
        ...
FROM t_test
WHERE deleted_time IS NOT NULL
        AND col1 = someValue
        ...
;


-- 表加一列,在id列之后
ALTER TABLE t_person
ADD COLUMN cnt BIGINT NOT NULL DEFAULT '0' COMMENT '数量' AFTER id
;

-- 捞取test数据
SELECT *
FROM t_person
WHERE name LIKE 'test%'
LIMIT 10
;

-- json get 通过key获取value
-- {\"test\":true}
SELECT json_col->'$.test'
FROM t_test
;


-- 捞出所有重复数量等于3的id
SELECT DISTINCT id
FROM t_test
GROUP BY id
HAVING COUNT(id) = 3
;


-- 今天从0点开始插入的数据行数
SELECT COUNT(*)
FROM `t_test`
WHERE gmt_create > DATE_FORMAT(CURDATE(),'%Y-%m-%d %H:%i:%s')
;


SHOW status LIKE 'Com_select%';
SHOW status LIKE 'Com_insert%';
SHOW status LIKE 'Com_update%';
SHOW status LIKE 'Com_delete%';
SHOW status LIKE 'Com_commit%';


SHOW status LIKE "Slow_queries";

status;
