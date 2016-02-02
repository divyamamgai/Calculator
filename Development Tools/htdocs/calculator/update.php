<a href="aboutgen.php" style="color:grey;text-decoration:none;">
   <h1 style="position:relative;top:15px;left:15px;width:600px">Calculator.1.0 About Editor</h1>
</a>
<hr style="border: 1px solid #666;">
<?php
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
<style>
   body {
   background:black;
   color:grey;
   font-family:VideoTerminalScreen-Normal;
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
   top:-15px;
   left:15px;
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
<?php
   $Title = "";
   $Information = "";
   $Properties = "";
   $Formulas = "";
   $Link = "";
   if(isset($_POST["Title"])){
   	$Title = $_POST["Title"];
   	$Information = mysql_real_escape_string($_POST["Information"]);
   	$Properties = mysql_real_escape_string($_POST["Properties"]);
   	$Formulas = mysql_real_escape_string($_POST["Formulas"]);
   	$Link = $_POST["Link"];
   }
   $QUERY = mysql_query("UPDATE about SET `Information`='".$Information."',`Properties`='".$Properties."',`Formulas`='".$Formulas."',`Link`='".$Link."' WHERE `Title` LIKE '".$Title."'");
   if($QUERY){
   
   echo "<h2 style=\"position:relative;left:15px;width:50%;\">Done! Data has been updated for ".$Title."!<br><br>Choose your action: </h2><br><b><a class=\"button\" href=\"index.php\">Home</a><a class=\"button\" href=\"aboutgen.php\" style=\"position:relative;left:20px;\">Add Another About Data</a></b>";
   }else echo "<h1>ERROR - MYSQL QUERY FAILED!</h1>";
?>
