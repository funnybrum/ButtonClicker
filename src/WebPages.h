const char CONFIG_PAGE[] PROGMEM = R"=====(
<HTML>
 <HEAD>
   <TITLE>Button Clicker</TITLE>
 </HEAD>
 <BODY>
  <form action="/settings" method="get">
   %s<br><br>
   %s<br><br>
   <small><em>Click commands examples:</em></small><br>
   <small><em>"0800:1p1p2222" - 8AM, click button 1, pause, click button 1, pause, click 4 times button 2</em></small><br>
   <small><em>"2210:1p3333" - 8:10PM, click button 1, pause, click 4 times button 3</em></small><br>
   %s<br><br>
   %s<br><br>
   %s<br><br>
   %s<br><br>
   <input type="submit" value="Save" style='width: 150px;'>
   &nbsp;&nbsp;&nbsp;
   <a href="/reboot">
    <button type="button" style='width: 150px;'>Restart</button>
   </a>
  </form>
 </BODY>
</HTML>
)=====";
