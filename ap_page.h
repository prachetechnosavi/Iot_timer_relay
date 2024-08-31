const char index_html[] PROGMEM = R"rawliteral(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Timer relay</title>
</head>
<style>
    html {
        font-family: Arial, Helvetica, sans-serif;
        display: inline-block;
        text-align: center;
    }
    h1 {
        font-size: 2 rem;
        color: black;
        font-family: Arial, Helvetica, sans-serif;
    }
    .top {
            overflow: hidden;
            background-color: #ffd256;
        }
</style>    
<body>
    <div class="top">
        <h1>Timer relay</h1>
    </div>   
    <div class="form">
        <h2>Enter time interval in seconds</h2>
        <form>
            <label for="sec">SECONDS:</label>
            <input type="number" id="sec" name="TI">
            <input type="submit" value="Submit" style="height:25px; width:100px">
        </form>
    </div> 
</body>
</html>
)rawliteral";
