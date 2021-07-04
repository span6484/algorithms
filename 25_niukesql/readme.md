## SQL1 查找最晚入职员工的所有信息

```sql
// 1. limit
select * from employees order by hire_date desc limit 1;

// 2. 最晚入职的不一定只有一个人
select * from employees where hire_date = (select max(hire_date) from employees);
```

## SQL2 查找入职员工时间排名倒数第三的员工所有信息

```sql
select * from employees where hire_date = (
select distinct hire_date from employees order by hire_date desc limit 2,1
);
```

## SQL3 查找当前薪水详情以及部门编号dept_no

注意这道题，需要过滤掉已经离职的

```sql
select s.emp_no, s.salary, s.from_date, s.to_date, d.dept_no
from salaries as s 
inner join dept_manager as d
on s.emp_no = d.emp_no
where s.to_date = '9999-01-01' 
and d.to_date = '9999-01-01'
order by s.emp_no;
```

## SQL4 查找所有已经分配部门的员工的last_name和first_name以及dept_no

```sql
select e.last_name, e.first_name, d.dept_no 
from employees as e
inner join dept_emp as d
on e.emp_no= d.emp_no;
```

## SQL5 查找所有员工的last_name和first_name以及对应部门

```sql
select e.last_name, e.first_name, d.dept_no 
from employees as e 
left outer join dept_emp as d
on e.emp_no = d.emp_no;
```

## SQL7

```sql
select emp_no, count(emp_no) as t from salaries group by emp_no having t > 15;
```

1. 用COUNT()函数和GROUP BY语句可以统计同一emp_no值的记录条数

注意 : 

WHERE语句在GROUP BY语句之前；SQL会在分组之前计算WHERE语句。   

HAVING语句在GROUP BY语句之后；SQL会在分组之后计算HAVING语句。

### SQL8

```sql
select distinct salary from salaries order by salary desc;
```

注意 : 

对于distinct与group by的使用: 

大表一般用distinct效率不高，大数据量的时候都禁止用distinct，建议用group by解决重复问题。

```sql
select salary from salaries group by salary order by salary desc;
```

## SQL10

not null 一般是整表扫描，所以我们会一般用left join

```sql
select e.emp_no from employees as e left join dept_manager as d
on e.emp_no = d.emp_no where d.dept_no is null;
```

## SQL11

```sql
select e.emp_no, m.emp_no as manager from 
dept_emp as e inner join dept_manager as m
on e.dept_no = m.dept_no
where e.emp_no <> m.emp_no;
```

## SQL12 

这道题表设计太傻比了，有点难，做不起

## SQL15 

```sql
select * from employees 
where emp_no % 2 = 1
and last_name <> 'Mary' 
order by hire_date desc;
```

## SQL16

```sql
select t.title, avg(s.salary) as avgs from
titles as t inner join salaries as s 
on t.emp_no = s.emp_no
group by title
order by avgs;
```

“Where” 是一个约束声明，使用Where来约束数据库的数据，Where是在结果返回之前起作用的，且Where中不能使用聚合函数。

“Having”是一个过滤声明，是在查询返回结果集以后对查询结果进行的过滤操作，在Having中可以使用聚合函数。

groupby 和 函数组合来统计

group by语法可以根据给定数据列的每个成员对查询结果进行分组统计，最终得到一个分组汇总表。

推荐阅读: https://blog.csdn.net/xxpyeippx/article/details/8059910

## SQL17

```sql
select emp_no, salary from salaries
where salary = (
    select salary from salaries group by salary order by salary desc limit 1, 1);
```


## SQL18

```sql
select e.emp_no, s.salary, e.last_name, e.first_name from 
employees as e inner join salaries as s 
on e.emp_no = s.emp_no
where s.salary = 
(
    select max(salary) from salaries 
    where salary != (
        select max(salary) from salaries)
);
```