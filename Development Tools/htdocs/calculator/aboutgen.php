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
<a href="aboutgen.php" style="color:grey;text-decoration:none;">
   <h1 style="position:relative;top:15px;left:15px;width:600px">Calculator.1.0 About Generator</h1>
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
   if(isset($_POST["Title"])&&strlen($_POST["Title"])!=0){
   $Title = $_POST["Title"];
   $Information = mysql_real_escape_string($_POST["Information"]);
   $Properties = mysql_real_escape_string($_POST["Properties"]);
   $Formulas = mysql_real_escape_string($_POST["Formulas"]);
   $Link = $_POST["Link"];
   $ID = rand();
   $QUERY = mysql_query("INSERT INTO `about` (`ID`,`Title`,`Information`,`Properties`,`Formulas`,`Link`) VALUES ('".$ID."','".$Title."','".$Information."','".$Properties."','".$Formulas."','".$Link."')");
   if($QUERY){
    echo "<div class=\"MSG\">Done! ".$Title." has been added.</div>";
   }else echo "<div class=\"MSG\">Error! Occurred Retry!</div>";
   }
   ?>
<div class="action"><a class="button" href="index.php"><b>Home</b></a><a class="button" href="aboutdatafilegen.php" style="position:relative;left:-2px;"><b>Generate About Data File</b></a></div>
<form action="aboutgen.php" method="post">
   <table style="width:100%;">
      <tbody>
         <tr align="middle">
            <td>
               Title:
            </td>
            <td>
               <input type="text" name="Title" style="width:390pt;">
            </td>
            <td>
               More Link:
            </td>
            <td>
               <input type="text" name="Link" style="width:390pt;">
            </td>
            <td></td>
            <td align="right">
               <input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;left:-7px;position:relative;" value="Add New About Data">
            </td>
         </tr>
         <tr align="middle">
            <td>
               Information:
            </td>
            <td>
               <textarea id="comments" rows="42" cols="70" name="Information" class="common"></textarea>
            </td>
            <td>
               Properties:
            </td>
            <td>
               <textarea id="comments"  rows="42" cols="70" name="Properties" class="common"></textarea>
            </td>
            <td>
               Formulas:
            </td>
            <td>
               <textarea id="comments"  rows="42" cols="70" name="Formulas" class="common"></textarea>
            </td>
         </tr>
      </tbody>
   </table>
</form>
<form action="edit.php" method="post" style="position:absolute;bottom:-16px;left:122px">
   <h2 style="width:50%;">Edit About Data</h2>
   <div style="position:relative;top:-20px;">Enter the Title:
      <input type="text" name="Title" style="width:390pt;">
      <input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;left:-5px;position:relative;top:1px;" value="Edit About Data">
   </div>
</form>