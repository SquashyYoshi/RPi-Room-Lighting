import os
from datetime import datetime
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
import helpers

STATES_HEAD = {"name": "name", "state": "state", "brightness": "brightness", "fanSpeed": "fanSpeed"}
ALARM_HEAD = {"day": "day", "time": "time"}
states = helpers.CSV("states.csv", STATES_HEAD)
alarms = helpers.CSV("alarms.csv", ALARM_HEAD)
app = Flask(__name__)

@app.route("/")
def index():
    
    return render_template("index.html")



