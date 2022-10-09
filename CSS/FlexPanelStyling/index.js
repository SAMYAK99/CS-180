const panels = document.querySelectorAll(".panel");

function toggleOpne() {
  this.classList.toggle("open");
  this.classList.toggle("open-active");
}
function toggleActive(e) {
  if (e.propertyName === "flex-grow") {
    this.classList.toggle("opne-active");
  }
}
panels.forEach((panel) => panel.addEventListener("click", toggleOpne));
panels.forEach((panel) =>
  panel.addEventListener("transistionend", toggleActive)
);
