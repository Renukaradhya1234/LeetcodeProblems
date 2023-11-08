SELECT count(ename)
FROM emp
WHERE comm is not null 
      and 
      deptno = 30;
