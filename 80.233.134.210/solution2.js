var modList = ["imm", "reg", "reg+imm","reg+reg"];
var regList = ["","","",""];
var codeList = ["mv","or","xor","and","not","add","sub","mul","sl","sr","inc","dec","push","pop","comp","jmp+","jmp0"];
var zeroFlag = false;

var workStack = [];

//TODO: Need to research what operations happen with one register and buff out the other functions.
//Don't forget to convert the decimal register values to HEX and place in fields. Then submit

function processImm(code, destReg, srcReg, immVal){
  //console.log("Processing IMM with code: " + code + " destReg: " + destReg + " srcReg: " + srcReg + " immVal: " + immVal);
  switch(codeList[code]){
      case "mv":
        console.log("Moved " + immVal + " to REG " + srcReg);
        regList[srcReg] = immVal;
        zeroFlag = (immVal == 0);
        break;
      case "or":
        console.log("OR " + immVal + " to REG " + srcReg);
        regList[srcReg] = regList[srcReg] | immVal;
        zeroFlag = (regList[srcReg] == 0);
        break;
      case "xor":
        console.log("XOR " + immVal + " to REG " + srcReg);
        regList[srcReg] = regList[srcReg] ^ immVal;
        zeroFlag = (regList[srcReg] == 0);
        break;
      case "and":
        console.log("AND " + immVal + " to REG " + srcReg);
        regList[srcReg] = regList[srcReg] & immVal;
        zeroFlag = (regList[srcReg] == 0);
        break;
      default:
        console.log("Operation " + code + ": " + codeList[code] + " IN A IMM?");
        break;
  }
}

function processReg(code, destReg, srcReg){
	console.log("Processing REG with code: " + code + " destReg: " + destReg + " srcReg: " + srcReg);
  switch(codeList[code]){
      case "mv":
        console.log("Moved REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      case "or":
        console.log("OR REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[destReg] | regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      case "xor":
        console.log("XOR REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[destReg] ^ regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      case "and":
        console.log("AND REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[destReg] & regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      default:
        console.log("Operation " + code + ": " + codeList[code] + " IN A REG?");
        break;
  }
}

function processRegImm(code, destReg, srcReg, immVal){
  console.log("Processing REGIMM with code: " + code + " destReg: " + destReg + " srcReg: " + srcReg + " immVal: " + immVal);

}

function processRegReg(code, destReg, srcReg){
	//console.log("Processing REGREG with code: " + code + " destReg: " + destReg + " srcReg: " + srcReg);
	switch(codeList[code]){
      case "mv":
        console.log("Moved REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      case "or":
        console.log("OR REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[destReg] | regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      case "xor":
        console.log("XOR REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[destReg] ^ regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      case "and":
        console.log("AND REG " + srcReg + " to REG " + destReg);
        regList[destReg] = regList[destReg] & regList[srcReg];
        zeroFlag = (regList[destReg] == 0);
        break;
      default:
        console.log("Operation " + code + ": " + codeList[code] + " IN A REGREG?");
        break;
  }

}

function processBinary(binArray){

    console.log(binArray);
    var binSplitArray = binArray.split(" ");

  for(var i = 0; i < binSplitArray.length; i++){
    //NEED TO DECODE BINARY and start printing operations   
    
    var curBin = binSplitArray[i];
    var code = parseInt(curBin.substr(0,8),2);
    
    //Increment the byte to check mod
    i++;
    curBin = binSplitArray[i];
    var mod = parseInt(curBin.substr(0,4),2);
    var destReg = parseInt(curBin.substr(4,2),2);
    var srcReg = parseInt(curBin.substr(6,2),2);
	
	//console.log("Checking MOD: " + mod + " should lead to " + modList[mod]);

    switch(modList[mod]){
      case "imm":
        i++;
        curBin = binSplitArray[i];
        i++;
        curBin += binSplitArray[i];
        var immVal = parseInt(curBin.substr(0,16),2);
        processImm(code, destReg, srcReg, immVal);       
        break;
      case "reg":
        processReg(code, destReg, srcReg); 
        break;
      case "reg+imm":
        i++;
        curBin = binSplitArray[i];
        i++;
        curBin += binSplitArray[i];
        var immVal = parseInt(curBin.substr(0,16),2);
        processRegImm(code, destReg, srcReg, immVal); 
        break;
      case "reg+reg":
        processRegReg(code, destReg, srcReg); 
        break;
	  default:
		console.log("ALERT: No mod for " + mod + "?");
		break;
    }
  }
}

function intToBinary(intBuffer){
  var cur = "";
  var out = "";
  for( var i = 0; i < intBuffer.length; i++){
    cur = (intBuffer[i] >>> 0).toString(2);

    if(cur.length > 8){

      var arr = cur.match(/.{1,8}/g);
      cur = arr[0] + " " + arr[1];
    }else{

      while(cur.length < 8){
        cur = "0" + cur;
      }
    }

    out += cur + " ";
  }
  return out.trim();
}

function getBinary(){

  var request = new XMLHttpRequest();
  request.open('GET',document.getElementsByTagName("a")[0].href,true);
  request.responseType = "arraybuffer";

  request.onload = function (oEvent) {
        var arrayBuffer = request.response;
        if(arrayBuffer){
            var byteArray = new Uint8Array(arrayBuffer);
            processBinary(intToBinary(byteArray));
        }
    }
    
    request.send(null);
}

getBinary();
