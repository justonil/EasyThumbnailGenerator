#pragma once

#include "CoreMinimal.h"
#include "SceneUtils.h"
#include "UObject/Object.h"
#include "EasyThumbnailGeneratorSessionSettings.generated.h"

UENUM()
enum class EEasyThumbnailGeneratorProjectionMode : uint8
{
    Perspective UMETA(DisplayName = "Perspective"),
    Orthographic UMETA(DisplayName = "Orthographic")
};

UENUM()
enum class EEasyThumbnailGeneratorFramingMode : uint8
{
    VisibleContent UMETA(DisplayName = "Visible Content"),
    BoundsCenter UMETA(DisplayName = "Bounds Center"),
    Pivot UMETA(DisplayName = "Pivot"),
    CustomOffset UMETA(DisplayName = "Custom Offset")
};

UENUM()
enum class EEasyThumbnailGeneratorPreset : uint8
{
    WeaponSide UMETA(DisplayName = "Weapon Side"),
    WeaponThreeQuarter UMETA(DisplayName = "Weapon 3/4"),
    AssetDefault UMETA(DisplayName = "Asset Default"),
    Custom UMETA(DisplayName = "Custom")
};

struct FEasyThumbnailGeneratorRenderSettings
{
    int32 OutputResolution = 1024;
    float FramePaddingPercent = 5.0f;
    EEasyThumbnailGeneratorFramingMode FramingMode = EEasyThumbnailGeneratorFramingMode::VisibleContent;
    FVector FrameOffset = FVector::ZeroVector;
    bool bShowBounds = false;
    bool bShowCheckerboard = false;
    bool bUsePreviewSceneSettings = false;
    bool bCaptureAntiAliasing = true;
    bool bCaptureTemporalAA = true;
    bool bCaptureEveryFrame = true;
    bool bCaptureOnMovement = true;
    bool bCaptureBloom = false;
    bool bCaptureVignette = false;
    bool bCaptureEyeAdaptation = false;
    bool bCapturePostProcessing = true;
    bool bCaptureTonemapper = true;
    bool bCaptureLighting = true;
    bool bCaptureReflections = true;
    bool bCaptureDeferredLighting = true;
    bool bCaptureMaterials = true;
    bool bCaptureDepthOfField = false;
    EEasyThumbnailGeneratorProjectionMode ProjectionMode = EEasyThumbnailGeneratorProjectionMode::Perspective;
    float CameraYaw = -90.0f;
    float CameraPitch = 0.0f;
    float PerspectiveFOV = 30.0f;
    float DirectionalLightIntensity = 8.0f;
    float DirectionalLightYaw = -35.0f;
    float DirectionalLightPitch = -45.0f;
    float SkyLightIntensity = 1.0f;
    bool bUseManualExposure = true;
    // Fixed editor-style EV100 used by both the live preview and final capture.
    float ExposureCompensation = 1.0f;

    // When true, generation uses the exact viewport camera instead of auto fitting.
    // This is used by Generate Current to keep the PNG framing close to the live preview.
    bool bUseExplicitCameraTransform = false;
    FVector ExplicitCameraLocation = FVector::ZeroVector;
    FRotator ExplicitCameraRotation = FRotator::ZeroRotator;
    float ExplicitOrthoWidth = 512.0f;
};

UCLASS(Transient)
class EASYTHUMBNAILGENERATOR_API UEasyThumbnailGeneratorSessionSettings : public UObject
{
    GENERATED_BODY()

public:
    UEasyThumbnailGeneratorSessionSettings();

    UPROPERTY(EditAnywhere, Category="Preset")
    EEasyThumbnailGeneratorPreset Preset;

    UPROPERTY(EditAnywhere, Category="Output", meta=(ClampMin="64", ClampMax="4096", UIMin="64", UIMax="4096"))
    int32 OutputResolution;

    UPROPERTY(EditAnywhere, Category="Output", meta=(ClampMin="0.0", ClampMax="50.0", UIMin="0.0", UIMax="50.0"))
    float FramePaddingPercent;

    UPROPERTY(EditAnywhere, Category="Framing", meta=(ToolTip="Visible Content uses projected mesh geometry to center the framing. Bounds Center, Pivot and Custom Offset keep their explicit framing anchors while still using geometry-aware fit extents."))
    EEasyThumbnailGeneratorFramingMode FramingMode;

    UPROPERTY(EditAnywhere, Category="Framing", meta=(EditCondition="FramingMode == EEasyThumbnailGeneratorFramingMode::CustomOffset", EditConditionHides, ToolTip="Offsets the framing center from the asset bounds center in asset-local units."))
    FVector FrameOffset;

    UPROPERTY(EditAnywhere, Category="Framing", meta=(DisplayName="Show Bounds", ToolTip="Draw the asset bounds in the live preview. This does not affect the exported PNG."))
    bool bShowBounds;

    UPROPERTY(EditAnywhere, Category="Preview", meta=(DisplayName="Checkerboard Background", ToolTip="Show Unreal Editor's alpha checkerboard behind the live preview. This does not affect the exported PNG."))
    bool bShowCheckerboard;

    UPROPERTY(EditAnywhere, Category="Preview", meta=(DisplayName="Use Preview Scene Settings", ToolTip="When enabled, the Preview Scene panel (environment, floor, grid, post process) drives the live preview instead of the plugin's own lighting/post-process settings."))
    bool bUsePreviewSceneSettings;

    UPROPERTY(EditAnywhere, Category="Capture", meta=(DisplayName="Anti-Aliasing"))
    bool bCaptureAntiAliasing;

    UPROPERTY(EditAnywhere, Category="Capture", meta=(DisplayName="Temporal AA (instead FXAA)"))
    bool bCaptureTemporalAA;

    UPROPERTY(EditAnywhere, Category="Capture", meta=(DisplayName="Capture Every Frame"))
    bool bCaptureEveryFrame;

    UPROPERTY(EditAnywhere, Category="Capture", meta=(DisplayName="Capture On Movement"))
    bool bCaptureOnMovement;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureBloom;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureVignette;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureEyeAdaptation;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCapturePostProcessing;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureTonemapper;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureLighting;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureReflections;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureDeferredLighting;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureMaterials;

    UPROPERTY(EditAnywhere, Category="Capture")
    bool bCaptureDepthOfField;

    UPROPERTY(EditAnywhere, Category="Camera")
    EEasyThumbnailGeneratorProjectionMode ProjectionMode;

    UPROPERTY(EditAnywhere, Category="Camera", meta=(ClampMin="-180.0", ClampMax="180.0", UIMin="-180.0", UIMax="180.0"))
    float CameraYaw;

    UPROPERTY(EditAnywhere, Category="Camera", meta=(ClampMin="-89.0", ClampMax="89.0", UIMin="-89.0", UIMax="89.0"))
    float CameraPitch;

    UPROPERTY(EditAnywhere, Category="Camera", meta=(ClampMin="5.0", ClampMax="120.0", UIMin="5.0", UIMax="120.0", EditCondition="ProjectionMode == EEasyThumbnailGeneratorProjectionMode::Perspective", EditConditionHides))
    float PerspectiveFOV;

    UPROPERTY(EditAnywhere, Category="Lighting", meta=(EditCondition="!bUsePreviewSceneSettings", ClampMin="0.0", ClampMax="50.0", UIMin="0.0", UIMax="50.0"))
    float DirectionalLightIntensity;

    UPROPERTY(EditAnywhere, Category="Lighting", meta=(EditCondition="!bUsePreviewSceneSettings", ClampMin="-180.0", ClampMax="180.0", UIMin="-180.0", UIMax="180.0"))
    float DirectionalLightYaw;

    UPROPERTY(EditAnywhere, Category="Lighting", meta=(EditCondition="!bUsePreviewSceneSettings", ClampMin="-89.0", ClampMax="89.0", UIMin="-89.0", UIMax="89.0"))
    float DirectionalLightPitch;

    UPROPERTY(EditAnywhere, Category="Lighting", meta=(EditCondition="!bUsePreviewSceneSettings", ClampMin="0.0", ClampMax="10.0", UIMin="0.0", UIMax="10.0"))
    float SkyLightIntensity;

    UPROPERTY(EditAnywhere, Category="Post Process", meta=(EditCondition="!bUsePreviewSceneSettings"))
    bool bUseManualExposure;

    UPROPERTY(EditAnywhere, Category="Post Process", meta=(DisplayName="Fixed EV100", ClampMin="-6.0", ClampMax="12.0", UIMin="-6.0", UIMax="12.0", EditCondition="!bUsePreviewSceneSettings && bUseManualExposure", EditConditionHides, ToolTip="Fixed EV100 used consistently by the live preview and exported PNG."))
    float ExposureCompensation;

    void ApplyPreset(EEasyThumbnailGeneratorPreset InPreset);
    void ApplyRenderSettings(const FEasyThumbnailGeneratorRenderSettings& Settings, EEasyThumbnailGeneratorPreset InPreset = EEasyThumbnailGeneratorPreset::Custom);
    FEasyThumbnailGeneratorRenderSettings MakeRenderSettings() const;
};
