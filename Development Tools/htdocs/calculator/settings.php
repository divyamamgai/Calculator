<?php
  // Generating Settings Variables.
  $SETTINGS_DATA = file_get_contents('settings_data.dat');
  $SETTINGS_SEPARATE_REGEX = "/\[*\]/";
  $INDIVIDUAL_SETTINGS = preg_split($SETTINGS_SEPARATE_REGEX,$SETTINGS_DATA);
  $SETTINGS = array();                                                                                      // Universal Settings array, Any variable can be accessed without the requirement of its Name.
  $SETTINGS_COUNT = 0;
  foreach($INDIVIDUAL_SETTINGS as $i){
      $INDIVIDUAL_SETTINGS_SEPARATE_REGEX = "%::\s*%";
      $INDIVIDUAL_SETTINGS_VALUES = preg_split($INDIVIDUAL_SETTINGS_SEPARATE_REGEX,substr($i,1,strlen($i)));
      if(isset($INDIVIDUAL_SETTINGS_VALUES[0])&&isset($INDIVIDUAL_SETTINGS_VALUES[1])){                     // Checking for their Availibility.
          $SETTINGS[$SETTINGS_COUNT] = $INDIVIDUAL_SETTINGS_VALUES[0];                                      // Getting Variable Name.
          $$SETTINGS[$SETTINGS_COUNT] = $INDIVIDUAL_SETTINGS_VALUES[1];                                     // Assigning value to the Variable recruited earlier.
      }
      $SETTINGS_COUNT++;
  }
  global $MYSQLHOST,$MYSQLUSER,$MYSQLPASS;
?>