/*
	Religious (
		STRING brainfuck
	): STRING
	
	Convert BF to Sacred
*/
function Religious(brainfuck)
{
	var lookup = [];
	lookup["_>"] = "))";
	lookup["_<"] = "((";
	lookup["_+"] = "()";
	lookup["_-"] = ")(";
	lookup["_."] = "(((";
	lookup["_,"] = ")))";
	lookup["_["] = "(";
	lookup["_]"] = ")";
	
	var commandments = ["())("];
	
	for(var i = 0, l = brainfuck.length; i < l; i++)
	{
		var character = brainfuck.charAt(i);
		
		if(typeof(lookup["_"+ character]) != "undefined")
		{
			commandments.push(lookup["_"+ character]);
		}
	}
	
	return commandments.join(" ");
}

/*
	Sacreligious (
		STRING sacred
	): STRING
	
	Convert Sacred to BF
	
	TBD!
*/
function Sacreligious(sacred)
{
	var goodCommandsLookup = [];
	goodCommandsLookup["_())("] = "";
	goodCommandsLookup["_))"] = ">";
	goodCommandsLookup["_(("] = "<";
	goodCommandsLookup["_()"] = "+";
	goodCommandsLookup["_)("] = "-";
	goodCommandsLookup["_((("] = ".";
	goodCommandsLookup["_)))"] = ",";
	goodCommandsLookup["_("] = "[";
	goodCommandsLookup["_)"] = "]";
	
	var badCommands = [
		{
			command: "((()",
			purpose: "Takes a numeric input."
		},
		{
			command: "())))",
			purpose: "Outputs the byte as a number."
		},
		{
			command: "()()",
			purpose: "Signifies code is Sacred mode 2"
		},
		{
			command: "((()))",
			purpose: "Converts the data strip into characters and evaluates them as if they were code."
		},
		{
			command: "((()()))",
			purpose: "Converts the data strip into characters and evaluates them as if they were code. Places this command at the end of the program to evaluate again the strip ad infinitum."
		}
	];
	
	var sanctified = "";
	var spaced = true;
	
	for(var i = 0, l = sacred.length; i < l; i++)
	{
		var c = sacred.charAt(i);
		
		if(c == "(" || c == ")")
		{
			sanctified += c;
			
			spaced = false;
		}
		else if(!spaced && (c == " " || c == "\t" || c == "\n" || c == "\r"))
		{
			sanctified +=" ";
			
			spaced = true;
		}
	}
	
	var brainfuck = "";
	var commandments = sanctified.split(" ");
	var badCommandments = [];
	
	for(var i = 0, n = commandments.length; i < n; i++)
	{
		if(typeof(goodCommandsLookup["_"+ commandments[i]]) != "undefined")
		{
			brainfuck += goodCommandsLookup["_"+ commandments[i]];
		}
		else
		{
			for(let iBad = 0, nBad = badCommands.length; iBad < nBad; iBad++)
			{
				if(commandments[i] == badCommands[iBad].command)
				{
					var alreadyListed = false;
					
					for(var iList = 0, nList = badCommandments.length; iList < nList; iList++)
					{
						if(badCommandments[iList].command == commandments[i])
						{
							alreadyListed = true;
							break;
						}
					}
					
					if(!alreadyListed)
					{
						badCommandments.push(badCommands[iBad]);
					}
					
					break;
				}
			}
		}
	}
	
	if(badCommandments.length > 0)
	{
		var warningsElement = document.getElementById("warnings");
		
		var warning = "<br /><b>Warning: some commands in that script don't have Brainfuck equivalents.<br />Your brainfuck will probably not work as intended.</b><br /><br /><table border='0' cellpadding='5' cellspacing='0' style='color:red;'>";
		
		for(var i = 0, n = badCommandments.length; i < n; i++)
		{
			warning +="<tr><td><b>"+ badCommandments[i].command +"</b></td><td>"+ badCommandments[i].purpose +"</td></tr>";
		}
		
		warning +="</table>";
		
		warningsElement.innerHTML = warning;
	}
	
	return brainfuck;
}

/*
	Convert (
		FUNCTION method
	): VOID
*/
function Convert(method)
{
	var warningsElement = document.getElementById("warnings");
	warningsElement.innerHTML = "";
	
	var inputElement = document.getElementById("inputCode");
	var outputElement = document.getElementById("outputCode");
	
	outputElement.value = method(inputElement.value);
}

/*
	Swap (
	): VOID
*/
function Swap()
{
	var inputElement = document.getElementById("inputCode");
	var outputElement = document.getElementById("outputCode");
	
	var input = inputElement.value;
	
	inputElement.value = outputElement.value;
	outputElement.value = input;
}




