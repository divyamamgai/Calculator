<?php
   $SETUP_FLAG = file_get_contents("setup_done_flag.bin");
   if(!$SETUP_FLAG){
		header('Location: setup.php');
		die();
   }
   include("settings.php");
   $Mysql_connection = mysql_connect($MYSQLHOST,$MYSQLUSER,$MYSQLPASS);
   if(!$Mysql_connection){
     echo "<h1>ERROR - MYSQL CONNECTION FAILED!</h1>";
	 $SetupFlagFile = fopen("setup_done_flag.bin",'w');
	 fwrite($SetupFlagFile,"0");
	 fclose($SetupFlagFile);
	 header('Location: setup.php');
	 die();
   }else mysql_select_db("cs_project");
   echo "<title>".$SITE_TITLE."</title>";
?>
<a href="index.php" style="color:grey;text-decoration:none;">
   <h1 style="position:relative;top:15px;left:15px;width:600px">Calculator.1.0 Development Tools</h1>
</a>
<hr style="border: 1px solid #666;">
<style>
   body {
   background:black;
   color:grey;
   font-family:VideoTerminalScreen-Normal;
   }
   textarea,input {
   border: 2px solid #666;
   background:black;
   font-size:12pt;
   font-family:VideoTerminalScreen-Normal;
   color:grey;
   padding-left:5px;
   padding-right:5px;
   padding-top:5px;
   padding-bottom:5px;
   outline:none;
   }
   input:hover{
   background:#666;
   color:black;
   outline:none;
   }
   div.MSG{
   position:absolute;
   top:10px;
   right:10px;
   border: 2px solid #666;
   font-size:12pt;
   padding-left:8px;
   padding-right:8px;
   padding-top:8px;
   padding-bottom:5px;
   background:#666;
   color:#000;
   }
   div.action{
   position:absolute;
   top:44px;
   left:39%;
   outline:none;
   }
   a.button{
   text-decoration:none;
   border: 2px solid #666;
   font-size:12pt;
   padding-left:8px;
   padding-right:8px;
   padding-top:8px;
   padding-bottom:5px;
   color:grey;
   outline:none;
   position:relative;
   left:20px;
   }
   a.button:hover{
   border: 2px solid #666;
   font-size:12pt;
   padding-left:8px;
   padding-right:8px;
   padding-top:8px;
   padding-bottom:5px;
   background:#666;
   color:#000;
   }
</style>
<h3 style="position:relative;top:0px;left:15px;width:600px">Choose your action: </h3>
<a class="button" href="aboutgen.php"><b>About Data Tools</b></a><br><br>
<a class="button" href="convertunitgen.php"><b>Unit Converter Data Tools</b></a><br><br>
<a class="button" href="aboutdatafilegen.php"><b>Generate About Data File</b></a><br><br>
<a class="button" href="convertunitgenraw.php"><b>Raw Data Database Generation</b></a><br><br>
<a class="button" href="convertunitdatagen.php"><b>Generate Unit Conversion Data File</b></a>