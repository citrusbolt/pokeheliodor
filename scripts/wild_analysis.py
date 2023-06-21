import os
import json
from operator import itemgetter
import species
import pprint

def processData(encounterTable, type):
    slot = 0

    if encounterTable['base_label'].startswith('gBattle'):
        version = 'BF'
    elif encounterTable['base_label'].startswith('SafariZone'):
        version = 'SZ'
    elif encounterTable['base_label'].startswith('sSafariZone'):
        version = 'SZ'
    elif encounterTable['base_label'].startswith('gSafariZone'):
        version = 'SZ'
    elif encounterTable['base_label'].startswith('sSixIslandAlteringCave'):
        version = 'AC'
    elif encounterTable['base_label'].startswith('gAlteringCave'):
        version = 'AC'
    elif encounterTable['base_label'].endswith('Ruby'):
        version = 'R'
    elif encounterTable['base_label'].endswith('Sapphire'):
        version = 'S'
    elif encounterTable['base_label'].endswith('FireRed'):
        version = 'FR'
    elif encounterTable['base_label'].endswith('LeafGreen'):
        version = 'LG'
    else:
        version = 'E'

    if type in encounterTable and version != 'BF' and version != 'SZ' and version != 'AC':
        for slotData in encounterTable[type]['mons']:
            currData = {'type': type, 'encounter_rate': encounterTable[type]['encounter_rate'], 'version': version, 'slot': slot, 'min_level': slotData['min_level'], 'max_level': slotData['max_level']}
            if slotData['species'] in processedData:
                processedData[slotData['species']].append(currData)
            else:
                processedData[slotData['species']] = [currData]
            slot += 1


__location__ = os.path.realpath(
    os.path.join(os.getcwd(), os.path.dirname(__file__)))

processedData = {}

with open(os.path.join(__location__, '../src/data/wild_encounters_rs.json'), 'r') as rs:
    rsData = rs.read()

data = json.loads(rsData)

for i in data['wild_encounter_groups'][0]['encounters']:
    processData(i, 'land_mons')
    processData(i, 'water_mons')
    processData(i, 'rock_smash_mons')
    processData(i, 'fishing_mons')


with open(os.path.join(__location__, '../src/data/wild_encounters_frlg.json'), 'r') as frlg:
    frlgData = frlg.read()

data = json.loads(frlgData)

for i in data['wild_encounter_groups'][0]['encounters']:
    processData(i, 'land_mons')
    processData(i, 'water_mons')
    processData(i, 'rock_smash_mons')
    processData(i, 'fishing_mons')


with open(os.path.join(__location__, '../src/data/wild_encounters_e.json'), 'r') as e:
    eData = e.read()

data = json.loads(eData)

for i in data['wild_encounter_groups'][0]['encounters']:
    processData(i, 'land_mons')
    processData(i, 'water_mons')
    processData(i, 'rock_smash_mons')
    processData(i, 'fishing_mons')


trimmedData = {}

for i in processedData:
    exists = set()
    trimmedTable = []

    for j in processedData[i]:
        tup = tuple(j.items())

        if tup not in exists:
            exists.add(tup)
            trimmedTable.append(j)

    trimmedData[i] = trimmedTable

sortedData = []
i = 0

for speciesName in species.speciesList:
    if speciesName in trimmedData:
        sortedData.append([speciesName, sorted(trimmedData[speciesName], key=itemgetter('slot'))])
        i += 1

pprint.pprint(sortedData)