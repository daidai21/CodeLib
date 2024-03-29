-- hive sql


-- 多行合并
select "tom" as name
union
select "jerry" as name
;

-- 建表

CREATE TABLE IF NOT EXISTS db_name.example_df(
    id INT COMMENT 'ID'
    ,name STRING COMMENT '姓名'
    ,age INT COMMENT '年龄'
    ,phone STRING COMMENT '电话'
) PARTITIONED BY date STRING COMMENT '日期'
LIFECYCLE 31 -- 生命周期
;

-- 实现 分组后随机取N条数据
select
    uid
    lvl
from (
    select  uid
            ,lvl
            ,row_number() over(partition by lvl order by rand()) rn
    from t_xxx
)
where  rn <= 10
;


-- Create Table as select (CTAS)
-- 只能是直接copy源表的ddl
-- 只能是下面简单的这种
-- https://stackoverflow.com/questions/22249739/create-hive-table-using-as-select-or-like-and-also-specify-delimiter
CREATE TABLE xxx.person 
AS 
select * 
from employee
;



-- convert array to string
select cast(array_bigint as string)
;


-- 更新多行，且每行的值不一样
INSERT INTO mhytable(storeId, date, ttl, bytes) 
VALUES 
('477866', '2019-02-05', 54543543, 100),
('6301', '2019-02-05', 54543543, 999999),
('12345', '2019-02-05', 54543543, 999999)
ON DUPLICATE KEY UPDATE
bytes = VALUES(bytes)
;



-- hive sql 子字符串出现的次数

size(split(get_json_object([sign_info], '$.item_sign_info.sku_sign_info'), '"sku_id"')) - 1

