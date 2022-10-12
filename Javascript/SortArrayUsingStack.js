<script>


function sortStack(input)
{
	var tmpStack = [];

	while (input.length!=0)
	{
	
		var tmp = input[input.length-1];
		input.pop();

	
		while (tmpStack.length!=0 &&
				tmpStack[tmpStack.length-1] < tmp)
		{
		
			input.push(tmpStack[tmpStack.length-1]);
			tmpStack.pop();
		}

		tmpStack.push(tmp);
	}

	return tmpStack;
}

function sortArrayUsingStacks(arr, n)
{

	var input = [];
	for (var i=0; i<n; i++)
	input.push(arr[i]);

	var tmpStack = sortStack(input);


	for (var i=0; i<n; i++)
	{
		arr[i] = tmpStack[tmpStack.length-1];
		tmpStack.pop();
	}
}


var arr = [10, 5, 15, 45];
var n = arr.length;
sortArrayUsingStacks(arr, n);
for (var i=0; i<n; i++)
document.write( arr[i] + " ");

</script>
