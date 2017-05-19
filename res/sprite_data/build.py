#!/usr/bin/env python

from glob import glob
from json import dump
from collections import deque
import sys
import os

ROOT = os.path.dirname(os.path.abspath(__file__))
DATA_DIR = os.path.join(ROOT, ".")
DATA_DIR_SCRIPTS = glob(os.path.join(DATA_DIR, "*.dat"))
OUTPUT_DIR = ROOT


def makeOutput():
    if not os.listdir(DATA_DIR):
        print('directory "{}" does not exist!'.format(DATA_DIR))
        return

    for data in DATA_DIR_SCRIPTS:
        jsonData = {}
        contents = deque([])
        name = ""
        with open(data, 'r') as infile:
            for line in infile.readlines():
                line = line.strip()
                if line:
                    contents.append(line)
            name = os.path.splitext(os.path.basename(infile.name))[0]

        spritesPerRow = int(contents.popleft().split()[1])
        spritesPerCol = int(contents.popleft().split()[1])
        spriteHeight = int(contents.popleft().split()[1])
        spriteWidth = int(contents.popleft().split()[1])
        spriteTypes = contents.popleft().split()[1]
        spriteTypes = spriteTypes.split(',')

        jsonData["name"] = name
        jsonData["sprites-per-row"] = spritesPerRow
        jsonData["sprites-per-col"] = spritesPerCol
        jsonData["sprite-width"] = spriteWidth
        jsonData["sprite-height"] = spriteHeight
        jsonData["types"] = spriteTypes

        jsonData["sprites"] = {}

        for spriteType in spriteTypes:
            jsonData["sprites"][spriteType] = {}

        for i, sprite in enumerate(contents):
            spriteName, spriteType = sprite.split()
            spriteType = spriteType.split("=")[1]

            jsonData["sprites"][spriteType][spriteName] = {}
            jsonData["sprites"][spriteType][spriteName]["x"] = i % spritesPerRow
            jsonData["sprites"][spriteType][spriteName]["y"] = 0 + i // spritesPerRow
            # jsonData["sprites"][spriteName]["type"] = spriteType

        jsonFile = os.path.join(OUTPUT_DIR, "{}.json".format(jsonData["name"]))
        with open(jsonFile, 'w') as outfile:
            dump(jsonData, outfile, indent=4)


if __name__ == "__main__":
    makeOutput()
