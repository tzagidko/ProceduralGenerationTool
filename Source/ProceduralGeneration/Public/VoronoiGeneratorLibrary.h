// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VoronoiGeneratorLibrary.generated.h"

USTRUCT(BlueprintType)
struct FVoronoiPoint {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float X;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Y;
};

USTRUCT(BlueprintType)
struct FVoronoiLineSegment {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVoronoiPoint Start;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVoronoiPoint End;
};

USTRUCT(BlueprintType)
struct FVoronoiCell {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVoronoiPoint Site;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FVoronoiLineSegment> Edges;
};
UCLASS()
class PROCEDURALGENERATION_API UVoronoiGeneratorLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, Category="Voronoi")
	static TArray<FVoronoiCell>GenerateVoronoiDiagram(const TArray<FVoronoiPoint>& Points, float MinX, float MaxX, float MinY, float MaxY);
protected:
	static float CalculateDistance(const FVector2D& Point1, const FVector2D& Point2);
};
