# SQL基础语句
### 1. 查看所有数据库，查看数据库中的表
>show databases; show tables;
### 2. 执行sql脚本
>source path\xxx.sql;
### 3. 登录mysql并在test数据库执行脚本
```sql
mysql –uroot –p123456 --default-character-set=utf8  -Dtest<d:\test\ss.sql #如果ss.sql中含有use test，就不需要-Dtest了
```
### 4. 查看当前所在数据库
>select database();
 status; 
 show tables;
