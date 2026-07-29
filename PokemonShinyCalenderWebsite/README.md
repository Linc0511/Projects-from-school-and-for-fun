The main idea for this project is to get a website running that is for anyone who wants to shiny hunt. This app is designed with the overall idea of tracking cateloguing any shiny you have. For those that don't know shiny poemon are a rare color variation of pokemon that just give the pokemon alternate colors. The features I want for this website are a catch claender of when you got the shiny, a current hunt tracker, when you open a shiny you can see and edit different deails about it sich as game rarity and ect.  
# Shiny Hunting Calendar — skeleton

Framework only. No hunt-tracking, anniversary, or facts logic is
implemented — just the plumbing to build on.

## Structure

```
shiny-calendar/
├── docker-compose.yml
├── data/                     # SQLite file lives here (persisted outside container)
└── app/
    ├── Dockerfile
    ├── requirements.txt
    ├── app.py                # Flask app, DB init, route stubs
    ├── templates/
    │   └── index.html        # page with 3 empty sections (hunt/anniversaries/facts)
    └── static/
        ├── css/style.css
        └── js/main.js         # fetches from the stub API endpoints
```

## Run it

```
docker compose up --build
```

Then open http://localhost:5000

## What's already wired up

- Flask serves one page (`/`) with three placeholder sections.
- Three DB tables are auto-created on startup: `hunts`,
  `shiny_anniversaries`, `hunt_facts` — schemas are guesses, change
  them however you like.
- Three empty API routes: `/api/hunts`, `/api/anniversaries`,
  `/api/facts` — each returns an empty list right now.
- `main.js` calls those three endpoints on page load and logs the
  result to the console, so you can confirm front-end <-> back-end
  wiring works before adding real logic.
- Live reload: the `app/` folder is mounted into the container, and
  Flask debug mode is on, so code edits show up without rebuilding.
- SQLite file is stored in `./data/`, outside the container, so it
  survives rebuilds.

## Where to build your features

- **Data model**: edit the `CREATE TABLE` statements in `init_db()`
  inside `app.py`.
- **Backend logic**: fill in `get_hunts()`, `get_anniversaries()`,
  `get_facts()` in `app.py` (or split into separate files/blueprints
  once it grows).
- **Frontend rendering**: replace the `console.log` calls in
  `main.js` with real DOM rendering into the matching `<section>` in
  `index.html`.

## Notes / things you might want to change later

- SQLite is fine for a local single-user tool; swap for Postgres in
  `docker-compose.yml` if you ever want multi-user or networked access.
- No auth — this is assumed to be a local, single-user app.
- Flask's built-in dev server is used here for simplicity; swap to
  gunicorn if you ever deploy this somewhere real.
