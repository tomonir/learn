
function GenerateCustomQueryReport()
{
  var spreadsheet = SpreadsheetApp.getActiveSpreadsheet();
  var sheet = spreadsheet.getSheets()[0];
  var config_sheet = spreadsheet.getSheetByName("Config");


  //get Target report Type
  var range = config_sheet.getRange("D1");
  var values = range.getValues();
  var reportType = values[0];

  //get query text
  var range = config_sheet.getRange("E1");
  var values = range.getValues();
  var querytext = values[0];

  //read config  Year
  var config_year = config_sheet.getRange("D3").getValues()[0];
  config_year = config_year.toString().split(".")[0];


  var filter_txt = "( ";
  var myQuery="";

  filter_txt +=" LOWER(D) contains  LOWER('"+querytext +"') ) and (YEAR(C) ="+config_year +"  ) ";
  myQuery = "=QUERY(Sheet1!A1:E, \"select A,B,C,D,E  where " + filter_txt +   " \")";

  //Logger.log(myQuery); 


  if (myQuery!="")
  {
    var sheet = spreadsheet.insertSheet(querytext+"");
    var r = sheet.getRange(1, 1).setFormula(myQuery);
  }

}



function GenerateIndividualReport()
{
  var spreadsheet = SpreadsheetApp.getActiveSpreadsheet();
  var sheet = spreadsheet.getSheets()[0];
  var config_sheet = spreadsheet.getSheetByName("Config");


  //get Target report Type
  var range = config_sheet.getRange("D1");
  var values = range.getValues();
  var reportType = values[0];


  //read config Month and Year
  var config_month = config_sheet.getRange("D4").getValues()[0]-1;
  var config_year = config_sheet.getRange("D3").getValues()[0];
  config_month = config_month.toString().split(".")[0]
  config_year = config_year.toString().split(".")[0]


  //get Category config
  range = config_sheet.getRange("A1:B");
  values = range.getValues(); 


  var myQuery="";
  if (reportType =='Unknown')
  {

      var filter_txt = "( "
      for (var i = 0; i < values.length; i++) {
    
        var category = values[i][0];

        if (category== '') break;

        if (category!='Unknown')
        {
          var filter_words = values[i][1].trim().split(",");
          

          for (var j=0;j<filter_words.length;j++)
          {
            filter_txt += " not D contains "+filter_words[j]+ " and ";
          }
                  
        }     
      }

      filter_txt +=" not D contains 'FAKE' ) and (YEAR(C) ="+config_year +" and Month(C)="+config_month+" ) and E < 0 "; 
      myQuery = "=QUERY(Sheet1!A1:E, \"select A,B,C,D,E  where " + filter_txt +   " \")";

      Logger.log(myQuery);            
  }
  else
  {

      for (var i = 0; i < values.length; i++) {
    
        var category = values[i][0];

        if (category==reportType)
        {
          var filter_words = values[i][1].trim().split(",");
          var filter_txt = "( "

          for (var j=0;j<filter_words.length;j++)
          {
            filter_txt += " D contains "+filter_words[j]+ " or ";
          }
          filter_txt +=" D contains 'FAKE' ) and (YEAR(C) ="+config_year +" and Month(C)="+config_month+" ) and E < 0 ";


          myQuery = "=QUERY(Sheet1!A1:E, \"select A,B,C,D,E  where " + filter_txt +   " \")";
          Logger.log(myQuery);  

        }
      }      
  } 

  if (myQuery!="")
  {
    var sheet = spreadsheet.insertSheet(reportType+"");
    var r = sheet.getRange(1, 1).setFormula(myQuery);
  }


}







function getCategoryWiseSpent(sp,config_sheet)
{



  //read configuration
  var range = config_sheet.getRange("A1:B");
  var values = range.getValues(); 


  //read config Month and Year
  var config_month = config_sheet.getRange("D4").getValues()[0]-1;
  var config_year = config_sheet.getRange("D3").getValues()[0];
  config_month = config_month.toString().split(".")[0]
  config_year = config_year.toString().split(".")[0]



  


  var cellNumber=12;

  columnData = ["Category","Amount"]
  config_sheet.getRange("C"+cellNumber+":D"+cellNumber).setValues([columnData]);
  cellNumber ++; 






  

  for (var i = 0; i < values.length; i++) {
  
    var category = values[i][0];


    var filter_words = values[i][1].trim().split(",");

    var filter_txt = "( "
    for (var j=0;j<filter_words.length;j++)
    {
      filter_txt += " D contains "+filter_words[j]+ " or ";
    }
    filter_txt +=" D contains 'FAKE' ) and (YEAR(C) ="+config_year +" and Month(C)="+config_month+" )  and E <0 ";

     
    var cell = config_sheet.getRange("C"+cellNumber);
    var myQuery = "=QUERY(Sheet1!A1:E, \"select '" + category +"' , sum (E) where " + filter_txt +   " \")";

    

    if (category =='')
      break;


    var columnData = [category,''];
    config_sheet.getRange("C"+cellNumber+":D"+cellNumber).setValues([columnData]);
    Logger.log(myQuery);
    var req = query(sp,myQuery);
    if (req.length>1) // There is some result out of the query
    {
      columnData = req[1];
      config_sheet.getRange("C"+cellNumber+":D"+cellNumber).setValues([columnData]);
      
    }
    cellNumber ++;
  }


      //new query for Unknown Category

      var filter_txt = "( "
      for (var i = 0; i < values.length; i++) {
    
        var category = values[i][0];

        if (category== '') break;

        if (category!='Unknown')
        {
          var filter_words = values[i][1].trim().split(",");
          

          for (var j=0;j<filter_words.length;j++)
          {
            filter_txt += " not D contains "+filter_words[j]+ " and ";
          }
                  
        }     
      }

      filter_txt +=" not D contains 'FAKE' ) and (YEAR(C) ="+config_year +" and Month(C)="+config_month+" ) and E < 0 "; 
      myQuery = "=QUERY(Sheet1!A1:E, \"select 'Unknown'  , sum (E) where " + filter_txt +   " \")";

      var columnData = ['Unknown',''];
      config_sheet.getRange("C"+cellNumber+":D"+cellNumber).setValues([columnData]);

      var req = query(sp,myQuery);
      if (req.length>1) // There is some result out of the query
      {
      columnData = req[1];
      config_sheet.getRange("C"+cellNumber+":D"+cellNumber).setValues([columnData]);
      
      }
      cellNumber ++;
      //Logger.log(myQuery)
 
  

}

function getZahlungSum(sp,config_sheet){

  //read config Month and Year
  var config_month = config_sheet.getRange("D4").getValues()[0]-1;// google spread sheet month start from zero!
  var config_year = config_sheet.getRange("D3").getValues()[0];
  config_month = config_month.toString().split(".")[0]
  config_year = config_year.toString().split(".")[0]

  
  myQuery = "=QUERY(Sheet1!A1:E, \" select SUM(E)   where  (YEAR(C) ="+config_year +" and Month(C)="+config_month+" and E<0 )  \")";
  //Logger.log(myQuery)

  cellNumber=9
  var columnData = ['']
  config_sheet.getRange("D"+cellNumber+":D"+cellNumber).setValues([columnData]);
  var req = query(sp,myQuery);
  if (req.length>1) // There is some result out of the query
  {
  var columnData = req[1];
  config_sheet.getRange("D"+cellNumber+":D"+cellNumber).setValues([columnData]);
  }

}


function getTotalIncome(sp,config_sheet){

  //read config Month and Year
  var config_month = config_sheet.getRange("D4").getValues()[0]-1;// google spread sheet month start from zero!
  var config_year = config_sheet.getRange("D3").getValues()[0];
  config_month = config_month.toString().split(".")[0]
  config_year = config_year.toString().split(".")[0]

  
  myQuery = "=QUERY(Sheet1!A1:E, \" select SUM(E)   where  E>0 and (YEAR(C) ="+config_year +" and Month(C)="+config_month+" )  \")";

  cellNumber=8

  var columnData = ['']
  config_sheet.getRange("D"+cellNumber+":D"+cellNumber).setValues([columnData]);

  var req = query(sp,myQuery);
  if (req.length>1) // There is some result out of the query
  {
  columnData = req[1];
  config_sheet.getRange("D"+cellNumber+":D"+cellNumber).setValues([columnData]);
  }

}


function showTotalZahlung ()
{
  var cell = sheet.getRange("G1");
  cell.setFormula("=QUERY(Sheet1!A1:E, \"select B , sum (E) group by B\")");
}


function query(sp,request) {
  var operation_sheet = sp.getSheetByName("Operator"); 
  var r = operation_sheet.getRange(1, 1).setFormula(request);

  var reply = operation_sheet.getDataRange().getValues();
  //sp.deleteSheet(sheet);

  //Logger.log(reply);
  return reply;
}



function MakeSummary() {

    var spreadsheet = SpreadsheetApp.getActiveSpreadsheet();
    var config_sheet = spreadsheet.getSheetByName("Config");

  


    getCategoryWiseSpent(spreadsheet,config_sheet);
    getZahlungSum(spreadsheet,config_sheet)
    getTotalIncome(spreadsheet,config_sheet)

  
}
