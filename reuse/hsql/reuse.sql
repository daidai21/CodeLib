
-- 多行合并
select "tom" as name
union
select "jerry" as name
;

-- 建表

CREATE TABLE IF NOT EXISTS example_df(
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
