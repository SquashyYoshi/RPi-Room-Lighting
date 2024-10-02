import csv
STATES_HEAD = {"name": "name", "state": "state", "brightness": "brightness", "fanSpeed": "fanSpeed"}
ALARM_HEAD = {"day": "day", "time": "time"}

def main(): #call main on bottom to reactivate this function
    while True:
        h = CSV("states.csv", STATES_HEAD)
        name = input("Name: ")
        if name == 'quit': return
        if name == '': h.lightSwitch("fan")
        field = input("field: ")
        newValue = input("Newvalue: ")
        h.update(name, field, newValue)

#reads csv file contents into a list of dicts
class CSV:
    def __init__(self, filename, header):
        self.filename = filename
        self.header = header

    def read(self):
        rows = []
        with open(self.filename, newline='') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                for key in row.keys(): #loop through each dict, if any '' found, replace with None
                    if row[key] == '': row[key] = None
                rows.append(row)
                #print(row)
            #print()
        return rows #list of dicts

    def update(self, name, field, newValue):
        states = self.read()
        for state in states:
            if state["name"] == name:
                state[field] = newValue
            print(state)
        with open(self.filename, 'w', newline='') as csvfile:
            writer = csv.DictWriter(csvfile, self.header)
            writer.writerow(self.header)
            writer.writerows(states)

    def lightSwitch(self, name):
        self.update(name, "state", self.getState(name, "state") != "True")

    def getState(self, name, field):
        states = self.read()
        for state in states:
            if state["name"] == name:
                if field == "brightness" or field == "fanSpeed":
                    return int(state[field])
                return state[field]

#main()


