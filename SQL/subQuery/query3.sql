SELECT emp.* , case 
                  WHEN sal > ( SELECT avg(sal)
                                FROM emp)
                        THEN 'HIGHER SALARY'
                  WHEN sal = ( SELECT avg(sal)
                                FROM emp)
                        THEN 'EQUAL TO AVG'
                  ELSE 'LOWER SALARY'
              end as 'REMARKS'
FROM emp;
