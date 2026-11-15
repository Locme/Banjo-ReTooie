//
// RT64
//

// Banjo-Tooie: 3D grass blades' pixel shader. A blade has its whole colour from its vertices (GrassBladeVS.hlsl: the
// ground's own texture, colour combiner and fog worked out there once a corner), so a pixel only writes that colour,
// solid. It stands in for the uber pixel shader, which did the same for blades but, built for every draw the game makes,
// holds far more of the graphics card's registers, so fewer blade pixels ran at once.

void PSMain(
      in float4 vertexPosition : SV_POSITION
    , in float2 vertexUV : TEXCOORD
    , in float4 vertexSmoothColor : COLOR0
    , nointerpolation in float4 vertexFlatColor : COLOR1
    , in float4 vertexFurAnchor : TEXCOORD1
    , [[vk::location(0)]] [[vk::index(0)]] out float4 pixelColor : SV_TARGET0
    , [[vk::location(0)]] [[vk::index(1)]] out float4 pixelAlpha : SV_TARGET1
)
{
    pixelColor = float4(vertexSmoothColor.rgb, 1.0f);
    pixelAlpha = 1.0f;
}
