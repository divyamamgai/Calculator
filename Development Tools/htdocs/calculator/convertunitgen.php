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
<a href="convertunitgen.php" style="color:grey;text-decoration:none;">
   <h1 style="position:relative;top:15px;left:15px;width:800px">Calculator.1.0 Unit Conversion Generator</h1>
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
</style>
<div class="action"><a class="button" href="index.php"><b>Home</b></a><a class="button" href="convertunitdatagen.php" style="position:relative;left:-2px;"><b>Generate Unit Conversion Data File</b></a><a class="button" href="convertunitgenraw.php" style="position:relative;left:-4px;"><b>Raw Data Database Generation</b></a></div>
<form action="convertunitgenadd.php" method="post">
   <input type="text" name="PostType" style="width:0px;height:0px;position:absolute;padding: 0px 0px 0px 0px;border:none;" value="1">
   <table style="width:50%;">
      <tbody>
         <tr align="left">
			<td>
               Type:
			</td>
			<td>
               <input type="text" name="Type" style="width:390pt;">
			</td>
		<tr>
            <td>
               No Of Units:
			</td>
			<td>
               <input type="text" name="NoOfUnits" style="width:390pt;">
            </td>
		</tr>
            <td align="right">
			</td>
			<td>
               <input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;" value="Add New Unit Conversion Data">
            </td>
         </tr>
      </tbody>
   </table>
</form>
<form action="convertunitgenedit.php" method="post" style="position:releative;">
   <input type="text" name="PostType" style="width:0px;height:0px;position:absolute;padding: 0px 0px 0px 0px;border:none;" value="1">
   <h2 style="width:50%;">Edit Unit Conversion Data</h2>
   <div style="position:relative;top:-20px;">Enter the Type:
      <input type="text" name="Type" style="width:390pt;">
      <input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;left:-5px;position:relative;top:1px;" value="Edit Unit Conversion Data">
   </div>
</form>
<form action="convertunitgenraw.php" method="post" style="position:releative;">
   <h2 style="width:50%;">Generate Unit Conversion Data From Raw Data File</h2>
   <table>
	<tbody>
		<tr>
			<td>Enter the Type:</td>
			<td><input type="text" name="Type" style="width:390pt;"></td>
		</tr>
		<tr>
			<td>Enter the File-Name:</td>
			<td><input type="text" name="FileName" style="width:390pt;"></td>
		</tr>
		<tr>
		<td></td>
		<td align="right">
			<input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;left:1px;position:relative;top:1px;" value="Generate Raw Data">
		</td>
	  </tbody>
	</table>
</form>
<h3 style="position:relative;top:15px;">
Current Data Status:-<br>
</h3>
<?php 
	$Query = mysql_query("SELECT Type, count(*) AS TypeCount FROM conversionunits GROUP BY Type");
	if($Query){
		while ($QueryArray = mysql_fetch_array($Query)) {
			echo "<b>".$QueryArray['Type']."</b> - ".$QueryArray['TypeCount']."<br>";
		}
	}else echo "Error Occured!";
?>