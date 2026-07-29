// Basic fetch helpers wired to the stub API routes.
// Nothing renders yet — this just proves the front-end <-> back-end
// connection works. Build your real rendering logic on top of this.

async function loadHunts() {
  const res = await fetch("/api/hunts");
  const data = await res.json();
  console.log("hunts:", data);
  // TODO: render into #current-hunt
}

async function loadAnniversaries() {
  const res = await fetch("/api/anniversaries");
  const data = await res.json();
  console.log("anniversaries:", data);
  // TODO: render into #anniversaries
}

async function loadFacts() {
  const res = await fetch("/api/facts");
  const data = await res.json();
  console.log("facts:", data);
  // TODO: render into #facts
}

document.addEventListener("DOMContentLoaded", () => {
  loadHunts();
  loadAnniversaries();
  loadFacts();
});
