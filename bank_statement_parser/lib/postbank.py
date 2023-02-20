import PyPDF2
import re


from lib.bank import Bank 
from datetime import datetime


from lib.helper import TextHandler
from lib.helper import PargerHelper



class PostbankParser(Bank):
    def __init__(self):
        pass



    def is_start_of_line(self,text, return_value):
        date_pattern = re.compile(r'\d{2}[.]\d{2}[.][/]\d{2}[.]\d{2}[.]')

        trimmed_text = text.replace(" ", "")
        matches = date_pattern.finditer(trimmed_text)

        for match in matches:
            return_value[0] = match.group()
            return True

        return False

	

    def get_zahlung_type(self,text):

        date = ""
        wrapper_date = [date]
        trimmed_txt =  text.replace(" ", "")


        if (self.is_start_of_line(text,wrapper_date)):
            zahlung_type = trimmed_txt.replace(wrapper_date[0],"")
            return zahlung_type
        return ""

    def deduce_buying_date(self,deduction_date,years):
        
        splited_date = deduction_date.split(".")
        if (len(splited_date)<4):
            return ""
        sorted_years = list(years)
        sorted_years.sort()


        #print (sorted_years)

        deduced_year=""
        

        if (len(sorted_years)>1):
            if (int (splited_date[1])>1 ):#Month is strated from february in this sheet
                deduced_year = sorted_years[0]
                return deduced_year+"-"+splited_date[1]+"-"+splited_date[0]
            else:
                deduced_year = sorted_years[1]
                return deduced_year+"-"+splited_date[1]+"-"+splited_date[0]

        elif (len(sorted_years)>0):
            deduced_year = sorted_years[0]
            return deduced_year+"-"+splited_date[1]+"-"+splited_date[0]
        else:
            return ""

    def parse(self,folder_path):

        files = PargerHelper.get_all_files(folder_path)
        lines=[]
        for file in files:
            print (file)
            # Open the PDF file

            
            with open(file, 'rb') as file:
                # Create a PDF reader object
                reader = PyPDF2.PdfReader(file)
                
                # Get the number of pages in the PDF
                num_pages = len(reader.pages)
               
                # Iterate through each page
                years=set()
                for page_num in range(num_pages):
                    # Get the page object
                    page = reader.pages[page_num]
                    
                    # Extract the text from the page
                    text = page.extract_text()
                    
                    # Print the text
                  

                    type_of_pyment       =""
                    real_date_of_purcess =""
                    start_of_line    =""
                    start_of_line_found = False
                    details_of_deduction = ""
                    amount_of_deduction  = ""

                    wrpper_formated_date = [start_of_line]
                    wrapper_formated_amount = [amount_of_deduction]
                    for line in text.splitlines():
                        #print (line )
                        #print ("--------------------------------------------------------------------------------------------------\n")

                        if (self.is_start_of_line(line,wrpper_formated_date)):
                            #date_of_deduction = line
                            details_of_deduction = ""
                            start_of_line_found= True
                            type_of_pyment = self.get_zahlung_type (line)

                        if (start_of_line_found):
                            details_of_deduction += line

                        if (real_date_of_purcess==""):
                            real_date_of_purcess = PargerHelper.get_date(line)

                        if (start_of_line_found and (PargerHelper.is_amount(line,wrapper_formated_amount))):
                            #amount_of_deduction = line
                            start_of_line_found = False
                            wrapper_formated_amount[0] = wrapper_formated_amount[0].replace (',','.')
                            #deduce date of purcess , in case not avilable

                            if (real_date_of_purcess==""  ):
                                real_date_of_purcess = self.deduce_buying_date(wrpper_formated_date[0],years)
                                
                            elif (PargerHelper.is_valid_year(real_date_of_purcess.split("-")[0])):
                                years.add(real_date_of_purcess.split("-")[0])
                            
                            lines.append (wrpper_formated_date[0] +"|" +type_of_pyment+"|" + real_date_of_purcess   +"|"+details_of_deduction+"|"+wrapper_formated_amount[0])
                            #writeToTextFile ("postbank_output.txt",wrpper_formated_date[0] +"|" +type_of_pyment+"|" + real_date_of_purcess   +"|"+details_of_deduction+"|"+wrapper_formated_amount[0])
                            #print (wrpper_formated_date[0] +"|" +type_of_pyment+"|" + real_date_of_purcess   +"|"+details_of_deduction+"|"+wrapper_formated_amount[0])

                            real_date_of_purcess = ""

        TextHandler.write_to_a_file("postbank_output.txt",lines)
                    #break

           


	 