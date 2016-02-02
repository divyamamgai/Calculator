<a href="convertunitgen.php" style="color:grey;text-decoration:none;">
   <h1 style="position:relative;top:15px;left:15px;width:800px">Calculator.1.0 Unit Conversion Generator</h1>
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
	$QUERY = mysql_query("SELECT DISTINCT Type FROM conversionunits");
	$i=0;
	if ($QUERY) {
		$AboutFile = fopen("convertdata.bin", 'w');
		fwrite($AboutFile, "");
		fclose($AboutFile);
		while ($QUERYARRAY = mysql_fetch_array($QUERY)) {
			$TYPE = $QUERYARRAY['Type'];
			$AboutString = $TYPE."#";
			$MYSQL_QUERY = mysql_query("SELECT * FROM conversionunits WHERE Type = '".$TYPE."'");
			while ($_QUERYARRAY = mysql_fetch_array($MYSQL_QUERY)) {
				$AboutString.=$_QUERYARRAY['UnitName']."|".$_QUERYARRAY['UnitValue']."%";
				$i++;
			}
			$AboutString.="\n";
			$AboutFile=fopen("convertdata.bin", 'a+');
			fwrite($AboutFile,$AboutString,strlen($AboutString));
			fclose($AboutFile);
		}
		echo "<h2 style=\"position:relative;left:15px;width:50%;\">Done! Unit Conversion Data file has been generated with ".$i." data.<br><br>Choose your action: </h2><br><b><a class=\"button\" href=\"index.php\">Home</a><a class=\"button\" href=\"convertunitgen.php\" style=\"position:relative;left:20px;\">Add Another Unit Conversion Data</a></b>";
	} else
		echo "<h1>ERROR - MYSQL QUERY FAILED!</h1>";
?>