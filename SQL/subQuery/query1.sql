SELECT ename, sal, job
FROM emp
WHERE sal * 12 > ( SELECT sal* 12
                    FROM  emp
                    WHERE ename = 'SMITH' )
      and
      sal * 12 < ( SELECT sal * 12
                    FROM emp 
                    WHERE ename = 'KING' );
