import React, { useState, useEffect } from "react";
import imge from "./images/elements.png";
import Jsdata from "./images/elements.json";
import "./App.css";

function App() {
  const [selectedAreas, setSelectedAreas] = useState([]);

  const handleAreaClick = (event, element) => {
    
    const clickedArea = {
      element,
      area_reference: event.target,
    };
    console.log("This is the element : -  ", clickedArea);
    const isSelected = event.target.classList.contains("selected");
    if (isSelected) {
      event.target.classList.remove("selected");
      setSelectedAreas((prevSelectedAreas) =>
        prevSelectedAreas.filter(
          (selectedArea) => selectedArea.element.fullXpath !== element.fullXpath
        )
      );
    } else {
      event.target.classList.add("selected");
      setSelectedAreas((prevSelectedAreas) => [...prevSelectedAreas, clickedArea]);
    }
  };

  const handleRemoveArea = (index, area_reference) => {
    // Remove "selected" class from the corresponding area element
    if (area_reference) {
      area_reference.classList.remove("selected");
    }

    setSelectedAreas((prevSelectedAreas) =>
      prevSelectedAreas.filter((_, i) => i !== index)
    );
  };

  const handleRenameLabel = (index, newLabel) => {
    setSelectedAreas((prevSelectedAreas) =>
      prevSelectedAreas.map((selectedArea, i) =>
        i === index ? { ...selectedArea, element: { ...selectedArea.element, label: newLabel } } : selectedArea
      )
    );
  };

  useEffect(() => {
    var width = 1280;
    var count = 0
    Jsdata.forEach((element) => {
      if (
      true
      ) {
        const map = document.getElementById("map");
        const area = document.createElement("area");
        area.id = count
        area.shape = "rect";
        area.label = element.label;
        area.style.top = element.top + "px";
        area.style.left = element.left + "px";
        area.style.width = element.width + "px";
        area.style.height = element.height + "px";
        area.className = "area";
        //area.dataset.class = element.Element_Name;
        area.ondblclick = (event) => handleAreaClick(event, element);
        map.appendChild(area);
      }
      count ++;
    });

    var css =
      "area:hover{ background-color: #00ff00; cursor: pointer;opacity: 0.25;}.area.selected{ background-color: #ff0000; opacity: 0.5;}";
    var style = document.createElement("style");
    if (style.styleSheet) {
      style.styleSheet.cssText = css;
    } else {
      style.appendChild(document.createTextNode(css));
    }
    document.getElementsByTagName("head")[0].appendChild(style);
  }, [Jsdata]);

  return (
    <div className="App">
      <img src={imge} id="imap" useMap="#my-map" alt="My image" />
      <map name="my-map" id="map"></map>
      <div>
        <h2>Selected Areas:</h2>
        <ul>
          {selectedAreas.map((selectedArea, index) => (
            <li key={index}>
              <input
                type="text"
                value={selectedArea.element.label}
                onChange={(e) => handleRenameLabel(index, e.target.value)}
              />
              <button onClick={() => handleRemoveArea(index, selectedArea.area_reference)}>
                Remove
              </button>
            </li>
          ))}
        </ul>
      </div>
    </div>
  );
}

export default App;
