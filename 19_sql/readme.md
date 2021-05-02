## 595. Big Countries

select name, population, area from World where area > 3000000 or population > 25000000;

# 多表查询

## 175. Combine Two Tables

1.确定查询结果

select FirstName, LastName, City, State

FirstName, LastName在Person表中

City, State 在 Address表，所以我们要多表查询

2.哪种联结呢？

多表的联结又分为以下几种类型：

1）左联结（left join），联结结果保留左表的全部数据

2）右联结（right join），联结结果保留右表的全部数据

3）内联结（inner join），取两表的公共数据

For each person in the Person table, regardless if there is an address for each of those people:

所以要以“Person”表进行左联结，保留左边表（Person表）里的全部数据。

from Person left join Address

3.两个表联结条件是什么？

两个表都有“PersonId”，所以联结条件为PersonId。

on Person.PersonId = Address.PersonId

```
select FirstName, LastName, City, State
from Person left join Address
on Person.PersonId = Address.PersonId;
```

# 如何查找第N高的数据？

## 176. Second Highest Salary

1.使用 limit 和 offset

limit y offset x 分句表示查询结果跳过 x 条数据，读取前 y 条数据

select distinct Salary
    from Employee
    order by Salary desc
    limit 1 offset 1

2.考虑特殊情况

题目要求，如果没有第二高的成绩，返回空值，所以这里用判断空值的函数（ifnull）函数来处理特殊情况。

ifnull(a,b)函数解释：

如果value1不是空，结果返回a

如果value1是空，结果返回b

对于本题的sql就是：


select ifnull(第1步的sql,null) as '2rd highest';

```
select ifnull(
    (select distinct Salary
    from Employee
    order by Salary desc
    limit 1 offset 1),
    null) as SecondHighestSalary;
```






