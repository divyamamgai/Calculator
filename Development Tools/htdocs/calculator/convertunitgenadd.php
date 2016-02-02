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
<?php
$PostType  = $_POST["PostType"];
$Type      = "";
$NoOfUnits = 0;
if ((isset($_POST["Type"]) && strlen($_POST["Type"]) != 0) && (isset($_POST["NoOfUnits"]) && $_POST["NoOfUnits"] != 0)) {
    $Type      = $_POST["Type"];
    $NoOfUnits = $_POST["NoOfUnits"];
    if ($PostType == 2) {
        for ($i = 1; $i <= $NoOfUnits; $i++) {
            $ID        = rand();
            $UnitName  = $_POST['UnitName_' . $i];
            $UnitValue = $_POST['UnitValue_' . $i];
            $QUERY     = mysql_query("INSERT INTO `conversionunits` (`ID`,`Type`,`UnitName`,`UnitValue`) VALUES ('" . $ID . "','" . $Type . "','" . $UnitName . "','" . $UnitValue . "')");
            if (!$QUERY)
                echo "Error! Please Try Again";
            else {
                if ($i == $NoOfUnits) {
                    header('Location: convertunitgendone.php?Type=1');
                    die();
                }
            }
        }
    }
} else {
    header('Location: convertunitgen.php');
    die();
}
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
<div class="action"><a class="button" href="index.php"><b>Home</b></a><a class="button" href="convertunitdatagen.php" style="position:relative;left:-2px;"><b>Generate Unit Conversion Data File</b></a><a class="button" href="convertunitgenraw.php" style="position:relative;left:-4px;"><b>Raw Data Database Generation</b></a></div>
<form action="convertunitgenadd.php" method="post">
   <input type="text" name="PostType" style="width:0px;height:0px;position:absolute;padding: 0px 0px 0px 0px;border:none;" value="2">
   <table style="width:50%;">
      <tbody>
         <tr align="left">
            <td width="25%">
               Type:
            </td>
            <td>
               <input type="text" name="Type" style="width:390pt;" value="<?php
echo $Type;
?>" readonly>
            </td>
         <tr>
            <td>
               No Of Units:
            </td>
            <td>
               <input type="text" name="NoOfUnits" style="width:390pt;" value="<?php
echo $NoOfUnits;
?>" readonly>
            </td>
         <tr>
            <td>
               Enter the Unit Conversions:
            </td>
            <td>
               <table id="Input" style="width:100%;border:2px solid #666;" cellspacing="0" cellpadding="0">
                  <tbody>
                     <tr>
                        <th>
                           Unit Name
                        </th>
                        <th>
                           Relation with a constant SI Unit
                        </th>
                     </tr>
                    <?php
						for ($i = 1; $i <= $NoOfUnits; $i++) {
							echo "<tr><td><input id=\"table_input_" . $i . "\" class=\"table_input\" type=\"text\" name=\"UnitName_" . $i . "\"></td><td><input id=\"table_input_" . $i . "\" class=\"table_input\" type=\"text\" name=\"UnitValue_" . $i . "\"></td></tr>";
						}
					?>
                  </tbody>
               </table>
            </td>
         </tr>
         </tr>
         <td>
         </td>
         <td align="right">
            <input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;position:relative;right:-2px;" value="Proceed to Add New Unit Conversion Data">
         </td>
         </tr>
      </tbody>
   </table>
</form>
<form action="edit.php" method="post" style="position:absolute;top:70px;right:15px">
   <h2 style="width:50%;">Edit Unit Conversion Data</h2>
   <div style="position:relative;top:-20px;">Enter the Type:
      <input type="text" name="Title" style="width:390pt;">
      <input type="submit" style="border: 2px solid #666;padding-top:8px;padding-left:8px;padding-right:8px;left:-5px;position:relative;top:1px;" value="Edit Unit Conversion Data">
   </div>
</form>
