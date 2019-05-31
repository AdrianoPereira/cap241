let overlayers = [{
     "title":"",
     "name":"",
     "host":"",
     "legend_color":"",
     "workspace":"",
     "active":true,
     "subdomains":null,
     "baselayer":false,
     "attribution":"",
     "opacity": 0.9
}]

var Terrabrasilis = require('terrabrasilis-api');

// just standard config
Terrabrasilis
    .map()
    .addBaseLayers()
    .addOverLayers()
    .enableDrawFeatureTool()
    .enableLayersControlTool()
    .enableScaleControlTool()
    .enableGeocodingTool();


// mount a simple map
Terrabrasilis
     .map(lat, lon, zoom, 'div to mount the map')
     .addBaseLayers()
     .addOverLayers(overlayers)
     .hideStandardLayerControl(); // disable LayerControl

// mount GeoJson layers (example)
geojsonLayers = [{
           "type":"point",
           "name":"cities",
           "active": true,
           "features":["all features points"]
     }];
Terrabrasilis
    .map()
    .addGeoJsonLayers(geojsonLayers);

