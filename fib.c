echo "Running tests..."
echo

output=$(./fib 1 r)
expected_output="0"

if [ $? -eq 0 ] ; then
  echo "Pass1: Program exited zero"
else
  echo "Fail1: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass1: Output is correct"
else
  echo "Fail1: Expected '$expected_output' but got: $output"
  exit 1
fi


output=$(./fib 2 r)
expected_output="1"

if [ $? -eq 0 ] ; then
  echo "Pass2: Program exited zero"
else
  echo "Fail2: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass2: Output is correct"
else
  echo "Fail2: Expected '$expected_output' but got: $output"
  exit 1
fi

output=$(./fib 4 r)
expected_output="2"

if [ $? -eq 0 ] ; then
  echo "Pass3: Program exited zero"
else
  echo "Fail3: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass3: Output is correct"
else
  echo "Fail3: Expected '$expected_output' but got: $output"
  exit 1
fi

echo
echo "All tests passed."

exit 0
