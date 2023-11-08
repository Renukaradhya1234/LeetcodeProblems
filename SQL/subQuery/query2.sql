SELECT ename, job, deptno
FROM emp
WHERE job = 'SALESMAN'
      and
      deptno = ( SELECT deptno
                  FROM dept
                  WHERE dname = 'SALES');
