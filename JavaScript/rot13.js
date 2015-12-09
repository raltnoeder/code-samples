var ROT_TABLE =
[
    "an",
    "bo",
    "cp",
    "dq",
    "er",
    "fs",
    "gt",
    "hu",
    "iv",
    "jw",
    "kx",
    "ly",
    "mz",
    "na",
    "ob",
    "pc",
    "qd",
    "re",
    "sf",
    "tg",
    "uh",
    "vi",
    "wj",
    "xk",
    "yl",
    "zm",
    "AN",
    "BO",
    "CP",
    "DQ",
    "ER",
    "FS",
    "GT",
    "HU",
    "IV",
    "JW",
    "KX",
    "LY",
    "MZ",
    "NA",
    "OB",
    "PC",
    "QD",
    "RE",
    "SF",
    "TG",
    "UH",
    "VI",
    "WJ",
    "XK",
    "YL",
    "ZM"
];

var charTable = new Array(256);

function initCharTable()
{
    for (var index = 0; index < 256; ++index)
    {
        charTable[index] = String.fromCharCode(index);
    }

    for (var index = 0; index < ROT_TABLE.length; ++index)
    {
        var tableIndex = ROT_TABLE[index][0].charCodeAt(0);
        charTable[tableIndex] = ROT_TABLE[index][1];
    }
}

function main()
{
    write("Enter a line of text to encode:\n");

    initCharTable();

    var textIn  = readline();
    var textOut = "";
    for (var index = 0; index < textIn.length; ++index)
    {
        var tableIndex = textIn.charCodeAt(index);
        textOut += charTable[tableIndex];
    }
    write(textOut + "\n");
}

main();
