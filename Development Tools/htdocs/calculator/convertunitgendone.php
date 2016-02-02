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
	if($_GET['Type']==1)
		echo "<h2 style=\"position:relative;left:15px;width:50%;\">Done! New Conversion Data has been successfully added!<br><br>Choose your action: </h2><br><b><a class=\"button\" href=\"index.php\">Home</a><a class=\"button\" href=\"convertunitgen.php\" style=\"position:relative;left:20px;\">Add Another Unit Conversion Data</a></b>";
	else
		echo "<h2 style=\"position:relative;left:15px;width:50%;\">Done! Conversion Data has been successfully updated!<br><br>Choose your action: </h2><br><b><a class=\"button\" href=\"index.php\">Home</a><a class=\"button\" href=\"convertunitgen.php\" style=\"position:relative;left:20px;\">Update Another Unit Conversion Data</a></b>";
?>
