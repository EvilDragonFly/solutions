# SQL语句面试常见题目
### 1.查询平均成绩大于60分的学生的学号和平均成绩
```sql
select s_id,AVG(s_score) from score group by s_id having AVG(s_score)>60
```