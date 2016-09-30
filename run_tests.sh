
#!/bin/bash


FAIL=0
for t in $(ls tests/????.dat); do
  cat $t | ./alg4_1.cpp.o > ${t}.out

  if cmp ${t}.out ${t}.ans; then
    echo "OK - $t"
  else
    echo "FAIL - $t"
    FAIL=1
  fi
  
done

if [ ${FAIL} -eq 1 ]; then
  echo "at least one test failed"
fi
