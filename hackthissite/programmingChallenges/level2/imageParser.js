function Morse(text) {
    function Analyze(s) {
        var j;
        var out='';
        mc={'A': '.-',
            'B': '-...',
            'C': '-.-.',
            'D': '-..',
            'E': '.',
            'F': '..-.',
            'G': '--.',
            'H': '....',
            'I': '..',
            'J': '.---',
            'K': '-.-',
            'L': '.-..',
            'M': '--',
            'N': '-.',
            'O': '---',
            'P': '.--.',
            'Q': '--.-',
            'R': '.-.',
            'S': '...',
            'T': '-',
            'U': '..-',
            'V': '...-',
            'W': '.--',
            'X': '-..-',
            'Y': '-.--',
            'Z': '--..',
            '0': '-----',
            '1': '.----',
            '2': '..---',
            '3': '...--',
            '4': '....-',
            '5': '.....',
            '6': '-....',
            '7': '--...',
            '8': '---..',
            '9': '----.',
            '.': '.-.-.-',
            ',': '--..--',
            indexOf: function (s) {
                for (var i in mc){
                    if (mc[i] == s) return i;
                }
                return ' ';
            },
            valueOf: function (s) {
                var ret=' ', j=s.toUpperCase();
                return (j in mc)? mc[j] + ret : ret;
            }
        };
        s = s.trim();
        if (s.length < 1) return s;
        if (s[0]!='.' && s[0]!='-') {
            s.forAll(function(e){
                out += mc.valueOf(e);
            });
        }
        else {
            var stanza = s.replace("\n"," ").split(" ");
            stanza.forEach(function(e){
                out += mc.indexOf(e);
            });
        }
        return out;
    }
    return Analyze(text);
}

var img = document.getElementsByTagName("img")[11];

var canvas = document.createElement("canvas");
    canvas.width = img.width;
        canvas.height = img.height;

var ctx = canvas.getContext("2d");
    ctx.drawImage(img, 0, 0);

var answer = "";
var lastFoundIndex = 0;

for(var i = 0; i < img.height; i++){
    for(var x = 0; x < img.width; x++){
      var data = ctx.getImageData(x,i,1,1).data;
      if(data[0] == 255){
        var ascii = (x + (i * 100));
        console.log("Found the ascii " + (ascii - lastFoundIndex));
        answer += String.fromCharCode(ascii - lastFoundIndex);
 
        lastFoundIndex = ascii;
      }
    }
}

console.log(Morse(answer));
