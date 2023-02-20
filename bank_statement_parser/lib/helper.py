import re
import os




class TextHandler:
    def __init__(self):
        pass

    # write a list of lines to a given file
    @staticmethod
    def write_to_a_file(fileName,lines):
        with open(fileName, 'w') as file:
            for item in lines:
                file.write("%s\n" % item)









class PargerHelper:
    def __init__(self):
        pass


    #return all files of a given folder path
    @staticmethod
    def get_all_files(folder_path="./"):

        files = []
        # r=root, d=directories, f = files
        for r, d, f in os.walk(folder_path):
            for file in f:
                files.append(os.path.join(r, file))
        return files


    #checks is a year is valid or not
    @staticmethod
    def is_valid_year(year_string):
        # Define the regular expression pattern for a 4-digit number
        pattern = r'^\d{4}$'
        # Use the re.match() function to check if the string matches the pattern
        match = re.match(pattern, year_string)
        if match:
            return True
        else:
            return False


    #extract a date from text line
    @staticmethod
    def get_date(text):

        return_date =""
        trimmed_text = text.replace(" ", "")


        pattern1 = "\d{4}[/.-]\d{2}[/.-]\d{2}"
        pattern2 = "\d{2}[/.-]\d{2}[/.-]\d{4}"
        pattern3 = "\d{2}[/.-]\d{2}[/.-]\d{2}"


        matches1 =  re.findall(pattern1, trimmed_text)
        matches2 =  re.findall(pattern2, trimmed_text)
        matches3 =  re.findall(pattern3, trimmed_text)

        for date in matches1:
            if (date.find("/") != -1):
                try:
                    date_object = datetime.strptime(date, "%Y/%m/%d")
                    return_date = date_object.strftime("%Y-%m-%d")
                    return return_date
                except:
                    return ""
            return_date = date
            return return_date


        for date in matches2:
            return_date = date
            try:
                date_object = datetime.strptime(return_date, "%d.%m.%Y")
                return_date = date_object.strftime("%Y-%m-%d")
                return return_date
            except:
                return_date =""
                break

        for date in matches3:
            return_date = date.split("/")
            if (len(return_date)>2):
                return_date = return_date[0]+"."+return_date[1]+"."+"20"+return_date[2]

            return_date = date.split(".")
            if (len(return_date)>2):
                return_date = return_date[0]+"."+return_date[1]+"."+"20"+return_date[2]

            try:
                date_object = datetime.strptime(return_date, "%d.%m.%Y")
                return_date = date_object.strftime("%Y-%m-%d")
            except:
                return_date =""
            break    


        return return_date

    #check a text contains a amount and return it
    def is_amount(text,return_value):
        date_pattern = re.compile(r'[-+]\d+,\d{2}')

        trimmed_text = text.replace(" ", "")
        trimmed_text = trimmed_text.replace(".", "")
        matches = date_pattern.finditer(trimmed_text)

        for match in matches:
            return_value[0] = match.group().replace("+", "")
            #print (return_value[0])
            return True

        return False

    
