var modList = ["imm", "reg", "reg+imm","reg+reg"];
var regList = ["","","",""];
var codeList = ["mv","or","xor","and","not","add","sub","mul","sl","sr","inc","dec","push","pop","comp","jmp+","jmp0"];

var workStack = [];

function processImm(code, immValue){
  console.log("REACHED IMM MOD");
}

function processReg(reg){


}

function processRegImm(){


}

function processRegReg(){


}

function processBinary(binArray){

  for(var i = 0; i < binArray.length;){
    //NEED TO DECODE BINARY and start printing operations   
    
    var curBin = binArray[i];
    var code = parseInt(curBin.substr(0,8),2);

    //Increment the byte to check mod
    i++;
    curBin = binArray[i];
    
    var mod = parseInt(curBin.substr(0,4),2);

    var destReg = "N/A";
    var srcReg = "N/A";

    switch(modList[mod]){
      case "imm":
        i++;
        curBin = parseInt(curBin.substr(0,8),2);
        processImm(code, curBin);       
        break;
      case "reg":
        
        break;
      case "reg+imm":
         
        break;
      case "reg+reg":
        
        break;
    }

  }

}

function charToBinary(text){
  var cur = "";
  var out = "";
  for( var i = 0; i < text.length; i++){
    cur = text[i].charCodeAt(0).toString(2);

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
  request.send(null);

  request.onreadystatechange = function () {
        if (request.readyState === 4 && request.status === 200) {
            var type = request.getResponseHeader('Content-Type');
            if (type.indexOf("text") !== 1) {
               processBinary(charToBinary(request.responseText).split(" "));
            }
        }
    }
}

getBinary();
