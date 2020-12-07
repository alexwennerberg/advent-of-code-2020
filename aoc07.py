# this day is in python, may redo in C later

import sys

lines = sys.stdin.read().split("\n")

rules = {}
for line in lines[:-1]:
   outer_bag = line.partition("bags")[0] 
   inner_bags = line.partition("contain")[2].split(",")
   parsed_bags = []
   for i in inner_bags:
       i = i.strip()
       if not i.startswith("no"):
           parsed_bags.append({"q": int(i[0]), "color": i.partition( " bag")[0].partition(" ")[2]})

   rules[outer_bag.strip()] = parsed_bags
seen = []
holds_gold = 0
for k,v in rules.items():
   seen  = [k]
   while seen:
       current = seen.pop()
       for value in rules[current]:
           seen.append(value["color"])
       if current == "shiny gold": 
           holds_gold += 1
       if len(seen) == 0:
           break

def get_subs(color):
    result = 0
    for value in rules[color]:
        result += value["q"] * (get_subs(value["color"]) + 1)
    return result

# part 1
print(holds_gold)
# part 2
print(get_subs("shiny gold"))
