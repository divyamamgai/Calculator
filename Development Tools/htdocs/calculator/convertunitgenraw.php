<a href="convertunitgen.php" style="color:grey;text-decoration:none;">
   <h1 style="position:relative;top:15px;left:15px;width:800px">Calculator.1.0 Unit Conversion Generator Raw</h1>
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
   left:45%;
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
   table#Input th {
   border:2px solid #666;
   padding: 5px 2px 3px 2px;
   background: #666;
   color:#000;
   }
   table#Input td {
   padding: 0px 2px 0px 2px;
   }
   input.table_input {
   width:100%;
   }
</style>
<?php
$UnitConversionString = "";
$Type = "";
$FileName = "";
if(isset($_POST['Type'])||isset($_GET['Type'])){
	if(isset($_POST['Type'])){
		$Type = $_POST['Type'];
		$FileName = $_POST['FileName'];
	}
	if(isset($_GET['Type'])){
		$Type = $_GET['Type'];
		$FileName = $_GET['FileName'];
	}
	$file = file($FileName);
	$i = 0;
	foreach ($file as $file_line_num => $file) {
		$ID = rand();
		$file = preg_replace( "#\%#", '`37`', $file );
		preg_match('/(.*?)\s\d/', $file, $matchString);
		$UnitConversionString.=htmlspecialchars($matchString[1])."|";
		$UnitName = htmlspecialchars($matchString[1]);
		preg_match('/\s([0-9].*?)\s\[/', $file, $matchNum);
		$UnitConversionString.=$matchNum[1]."%";
		$UnitValue = $matchNum[1];
		$QUERY=mysql_query("INSERT INTO `conversionunits` (`ID`,`Type`,`UnitName`,`UnitValue`) VALUES ('" . $ID . "','" . $Type . "','" . mysql_real_escape_string($UnitName) . "','" . $UnitValue . "')");
		if(!$QUERY){
		    echo "<h3>Error! MYSQL QUERY!</h3><br>ID: " . $ID . " | Type: " . $Type . " | UnitName: " . $UnitName . " | UnitValue: ". $UnitValue . "<hr>";
		}else $i++;
	}
	echo "<h1>Data has been generated for ".$Type." [and is saved to the database] :-</h1>";
	echo $UnitConversionString;
   echo "<h1 style=\"position:relative;left:15px;width:50%;\">Done! Unit Conversion database has been generated! Total of ".$i." data were added.<br><br>Choose your action: </h1><br><b><a class=\"button\" href=\"index.php\">Home</a><a class=\"button\" href=\"convertunitgen.php\" style=\"position:relative;left:20px;\">Add Another Unit Conversion Data</a></b>";	
}else echo "<h1>Error! Please specify Type!</h1>Eg: URL should be of this form - localhost/csproj/convertunitgenraw.php?Type=TYPE , here TYPE can be replaced by the unit type you want."; 
?>