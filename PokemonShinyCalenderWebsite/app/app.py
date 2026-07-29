"""
Shiny Hunting Calendar — app skeleton.

This file wires up the Flask app, a SQLite connection, and empty route
stubs for the three feature areas you mentioned:
  1. Anniversaries  (shiny_anniversaries)
  2. Current hunt tracker  (hunts)
  3. Hunt facts  (hunt_facts)

No feature logic is implemented yet — just the plumbing so you have
somewhere to build. Table schemas below are guesses to get you started;
change them freely once you design the real data model.
"""

import os
import sqlite3

from flask import Flask, g, jsonify, render_template

DATABASE_PATH = os.environ.get("DATABASE_PATH", "/data/shiny_calendar.db")

app = Flask(__name__)


# ---------------------------------------------------------------------------
# Database helpers
# ---------------------------------------------------------------------------

def get_db():
    """Open a new database connection for this request if one doesn't exist."""
    if "db" not in g:
        g.db = sqlite3.connect(DATABASE_PATH)
        g.db.row_factory = sqlite3.Row
    return g.db


@app.teardown_appcontext
def close_db(exception=None):
    db = g.pop("db", None)
    if db is not None:
        db.close()


def init_db():
    """Create tables if they don't exist yet. Runs once at startup."""
    db = sqlite3.connect(DATABASE_PATH)
    db.executescript(
        """
        CREATE TABLE IF NOT EXISTS hunts (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            pokemon_name TEXT NOT NULL,
            method TEXT,              -- e.g. "random encounter", "masuda", "SOS"
            game TEXT,                -- e.g. "Scarlet", "HeartGold"
            encounter_count INTEGER DEFAULT 0,
            started_at TEXT,
            completed_at TEXT,
            is_active INTEGER DEFAULT 1
        );

        CREATE TABLE IF NOT EXISTS shiny_anniversaries (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            pokemon_name TEXT NOT NULL,
            date_caught TEXT NOT NULL,   -- ISO date, e.g. "2023-06-14"
            game TEXT,
            notes TEXT
        );

        CREATE TABLE IF NOT EXISTS hunt_facts (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            category TEXT,        -- e.g. "odds", "trivia", "tip"
            fact_text TEXT NOT NULL
        );
        """
    )
    db.commit()
    db.close()


# ---------------------------------------------------------------------------
# Page routes (server-rendered HTML)
# ---------------------------------------------------------------------------

@app.route("/")
def index():
    return render_template("index.html")


# ---------------------------------------------------------------------------
# API routes — stubs only, wire up real logic later
# ---------------------------------------------------------------------------

@app.route("/api/hunts", methods=["GET"])
def get_hunts():
    """Return current/past hunts. TODO: implement query + filtering."""
    return jsonify({"hunts": []})


@app.route("/api/anniversaries", methods=["GET"])
def get_anniversaries():
    """Return upcoming shiny anniversaries. TODO: implement date logic."""
    return jsonify({"anniversaries": []})


@app.route("/api/facts", methods=["GET"])
def get_facts():
    """Return hunt facts, maybe a random one for the homepage. TODO: implement."""
    return jsonify({"facts": []})


@app.route("/api/health", methods=["GET"])
def health():
    """Simple health check so you can confirm the container is alive."""
    return jsonify({"status": "ok"})


# ---------------------------------------------------------------------------

init_db()

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000, debug=True)
